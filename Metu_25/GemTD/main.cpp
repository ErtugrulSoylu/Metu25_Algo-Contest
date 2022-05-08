#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

typedef long long ll;

int n, portalLength, emptyScore, fullScore, i1, j1, i2, j2, cost, dfb;

vector<vector<int>> grid;

map<pair<int, int>, vector<vector<int>>> portalAdj;

void find_min_distance(pair<int, int> p1, pair<int, int> p2) {
    vector<vector<int>> distances(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

    distances[p1.first][p1.second] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;

    pq.push({ 0, p1 });

    while (!pq.empty()) {
        dfb = -pq.top().first;
        i1 = pq.top().second.first;
        j1 = pq.top().second.second;

        pq.pop();

        if (visited[i1][j1]) continue;

        visited[i1][j1] = true;

        for (auto adj : portalAdj[{i1, j1}]) {
            i2 = adj[0];
            j2 = adj[1];
            cost = adj[2];

            if (distances[i2][j2] > dfb + cost) {
                distances[i2][j2] = dfb + cost;

                pq.push({ -distances[i2][j2], { i2, j2 } });
            }
        }
    }

    i1 = p2.first;
    j1 = p2.second;

    while (i1 != p1.first || j1 != p1.second) {
        grid[i1][j1]++;

        for (auto adj : portalAdj[{ i1, j1 }]) {
            i2 = adj[0];
            j2 = adj[1];
            cost = adj[2];

            if (distances[i2][j2] + cost == distances[i1][j1]) {
                i1 = i2;
                j1 = j2;

                break;
            }
        }
    }
}

int maxim(int n) {
    vector<vector<int>> res(n,vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            res[i][j] = grid[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 1; j < n; j++)
            res[i][j] += res[i][j - 1];
    int startCol = 0, endCol = 0, startRow = 0, endRow = 0;
    int maxSum = INT_MIN;

    for(int firstCol = 0; firstCol < n; firstCol++) {
        for(int secondCol = firstCol; secondCol < n; secondCol++) {
            int tmp[n]; 
            for(int row=0;row<n;row++)
                tmp[row] = res[row][secondCol] - (firstCol>0 ? res[row][firstCol-1] : 0);
            int curSum = 0, curMaxSum = 0;
            int curStartRow = 0, tmpStartRow = 0, curEndRow = -1;
            
            for(int curRow=0;curRow<n;curRow++){
                curSum += tmp[curRow];
                if(curSum < 0) {
                    curSum = 0;
                    tmpStartRow = curRow+1;
                } else if(curSum > curMaxSum) {
                    curMaxSum = curSum;
                    curStartRow = tmpStartRow;
                    curEndRow = curRow;
                }
            }
            if(curEndRow == -1) {
                curMaxSum = tmp[0];
                curStartRow = 0;
                curEndRow = 0;
                for(int i=1;i<n;i++){
                    if(tmp[i] > curMaxSum){
                        curMaxSum = tmp[0];
                        curStartRow = i;
                        curEndRow = i;
                    }
                }
            }
            if(curMaxSum > maxSum){
                maxSum = curMaxSum;
                startCol = firstCol;
                endCol = secondCol;
                startRow = curStartRow;
                endRow = curEndRow;
            }
        }
    }

    return maxSum;
}

int main() {
    cin >> n >> portalLength >> emptyScore >> fullScore;

    grid.resize(n + 1, vector<int>(n + 1, 0));

    vector<pair<int, int>> path(5);

    for (int i = 0; i < 5; i++) {
        cin >> i1 >> j1;

        path[i] = { i1, j1 };
    }

    for (int i = 0; i < portalLength; i++) {
        cin >> i1 >> j1 >> i2 >> j2 >> cost;

        portalAdj[{i1, j1}].push_back({ i2, j2, cost });
        portalAdj[{i2, j2}].push_back({ i1, j1, cost });
    }

    grid[path[0].first][path[0].second]++;

    for (int i = 0; i < 4; i++) {
        find_min_distance(path[i], path[i+1]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            grid[i][j] = grid[i][j] ? grid[i][j] * fullScore : emptyScore;

    cout << maxim(n + 1) << endl;

    return 0;
}