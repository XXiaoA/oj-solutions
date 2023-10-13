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
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, m, w[3500], v[3500], dp[13000] = {0};
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        w[i] = read(), v[i] = read();
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[m];

    return 0;
}
