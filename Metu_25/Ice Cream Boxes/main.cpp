#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }
    int res = nums[0];
    int count = 1;
    int max_num = *max_element(nums.begin(), nums.end());
    for (int i = 2; i <= max_num / 2 + 1; i++) {
        int tmp = 0;
        for (auto a : nums) {
            if (a%i == 0) {
                tmp++;
            }
        }
        if (tmp > count) {
            count = tmp;
            res = i;
        }
    }
    cout << res << endl;
    return 0;
}