#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;
vector<vector<int>> grid;
vector<int> horiz;
vector<int> vert;

int main() {
    int row, col;

    vector<string> vec;
    cin >> row >> col;
    string tmp;
    for (int i = 0; i < row; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }

    for (int i = 0; i < vec.size(); i++) {
        vector<int> tmp;
        grid.push_back(tmp);
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            if (vec[i][j] == '*')
                grid[i].push_back(-2);
            else if (vec[i][j] == '.')
                grid[i].push_back(-1);
            else if (vec[i][j] == 'A')
                grid[i].push_back(0);
            else if (vec[i][j] == 'Z')
                grid[i].push_back(100000);
        }
    }

    int n;
    cin >> n;
    int num;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cin >> num;
        if (c == 'N' || c == 'W')
            num = -num;
        if (c == 'N' || c == 'S')
            vert.push_back(num);
        if (c == 'E' || c == 'W')
            horiz.push_back(num);
    }

    queue<pair<int, int>> q;
    int size = 0;
    int res = -1;
    for (int i = 0; i < vec.size() && q.empty(); i++) {
        for (int j = 0; j < vec[0].size(); j++) {
            if (vec[i][j] == 'A')
                q.push({i, j});
        }
    }

    int step = 0;
    while (!q.empty()) {
        size = q.size();
        step++;
        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            for (auto a : horiz) {
                int sum = col + a;
                if (sum >= grid[0].size() || sum < 0 || grid[row][sum] == -2 || (grid[row][sum] > 0 && grid[row][sum] <= step))
                    continue ;
                if (grid[row][sum] == 100000) {
                    cout << step << endl;
                    return 0;
                }
                grid[row][sum] = step;
                q.push({row, sum});
            }
            for (auto a : vert) {
                int sum = row + a;
                if (sum >= grid.size() || sum < 0 || grid[sum][col] == -2 || (grid[sum][col] > 0 && grid[sum][col] <= step))
                    continue ;
                if (grid[sum][col] == 100000) {
                    cout << step << endl;
                    return 0;
                }
                grid[sum][col] = step;
                q.push({sum, col});
            }
            q.pop();
        }
    }
    cout << -1 << endl;
    return 0;
}