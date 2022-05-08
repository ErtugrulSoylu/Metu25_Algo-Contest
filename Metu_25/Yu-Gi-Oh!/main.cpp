#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

int main() {
    int n;

    const int MOD = 1e9 + 7;
    cin >> n;
    vector<ll> vec(n + 1, 0);
    vec[1] = 1;
    vector<ll> tmp = vec;
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            vec[j] = tmp[j] * j + tmp[j - 1];
            vec[j] %= MOD; 
        }
        tmp = vec;
    }
    for (int i = 1; i <= n; i++) {
        cout << vec[i];
        if (i != n)
            cout << " ";
    }
    cout << endl;
    return 0;
}
