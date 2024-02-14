#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, num, sum = 0, ans;
    vector<int> nums;
    cin >> n;
    while (n--) {
        cin >> num;
        nums.push_back(num);
    }
    ans = nums.at(0);
    for (const auto &num : nums) {
        sum += num;
        ans = max(sum, ans);
        if (sum < 0)
            sum = 0;
    }

    cout << ans << endl;

    return 0;
}
