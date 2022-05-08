#include <string>
#include <iostream>
#include <vector>
#include <map>
#define ll long long

using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(500, vector<int>(500));
    map<int, int> dp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[v[i][j] - i - j]++;

    int res = INT_MIN;
    int ret;
    for (auto it : dp) {
        if (it.second > res) {
            res = it.second;
            ret = it.first;
        }
    }
    res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] - i - j != ret)
                res++;
        }
    }
    cout << res << endl;
}
