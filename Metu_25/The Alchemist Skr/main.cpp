#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;


int main()
{
    vector<ll> n(3);
    cin >> n[0] >> n[1] >> n[2];

    sort(n.begin(), n.end());

    if ((n[1] - n[0])%2 == 0) {
        cout << n[1] << endl;
        return 0;
    }

    cout << n[2] << endl;
    return(0);
}
