#include <algorithm>
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
#ifdef LOCAL
    int n = 11;
#else
    int n = read();
#endif
    int dp[1005] = {0}, sum[1005] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            sum[j] += i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] = max(dp[j - i] + sum[i], dp[j]);
        }
    }
    cout << dp[n] << endl;

    return 0;
}
