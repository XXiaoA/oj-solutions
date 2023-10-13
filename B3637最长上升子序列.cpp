#include <iostream>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    // clang-format off
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    // clang-format on
    return x * w;
}

int main() {
    ios::sync_with_stdio(false);
    int n, nums[5005], dp[5005] = {1}, ans = 0;
    n = read();
    for (int i = 1; i <= n; i++)
        nums[i] = read();
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
