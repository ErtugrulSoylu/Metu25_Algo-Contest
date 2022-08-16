#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>

using namespace std;
map<vector<int>, int> dp;
vector<int> vec;
int k;
int rec(vector<int> &vec, int i, int num, int most) {
    if (most < 0)
        return -999;
    if (i >= vec.size())
        return 0;
    if (dp[{i, num, most}])
        return dp[{i, num, most}];
    int res;
    if (vec[i] < num) {
        res = rec(vec, i + 1, num, most);
    } else if (vec[i] == num) {
        int tmp1 = 1 + rec(vec, i + 1, num, most - 1);
        int tmp2 = rec(vec, i + 1, num, most);
        res = max(tmp1, tmp2);
    } else {
        int tmp1 = 1 + rec(vec, i + 1, vec[i], k - 1);
        int tmp2 = rec(vec, i + 1, num, most);
        res = max(tmp1, tmp2);
    }
    dp[{i, num, most}] = res;
    return res;
}

int main() {
    int n, tmp;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        vec.push_back(tmp);
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int max = 0;
    for (int i = n-1; i >= 0; i--) {
        tmp = rec(vec, i, 0, k);
        max = tmp > max ? tmp : max;
    }
    cout << max << endl;
    return 0;
}
