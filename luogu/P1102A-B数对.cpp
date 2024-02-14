#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    int n, c, x;
    vector<int> nums;
    map<int, int> cnt;
    ll ans = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
        cnt[x]++;
        nums.back() -= c;
    }
    for (const auto &num : nums) {
        ans += cnt[num];
    }
    cout << ans << endl;

    return 0;
}
