#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int t, m, cost[105], value[105], mem[105][1005];

int dfs(int pos, int time_left) {
    if (mem[pos][time_left] != -1)
        return mem[pos][time_left];
    if (pos == m + 1)
        return mem[pos][time_left] = 0;
    int ans1, ans2 = 0x80000000;
    ans1 = dfs(pos + 1, time_left);
    if (time_left >= cost[pos])
        ans2 = dfs(pos + 1, time_left - cost[pos]) + value[pos];
    return mem[pos][time_left] = max(ans1, ans2);
}

int main() {
#ifdef LOCAL
    freopen("P1048.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    t = read(), m = read();
    // for (int i = 0; i < m; i++) {
    //     cost[i] = read(), value[i] = read();
    // }
    // memset(mem, -1, sizeof(mem));
    // cout << dfs(0, t) << endl;

    int dp[1005] = {0};
    for (int i = 1; i <= m; i++) {
        cost[i] = read(), value[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= cost[i]; j--) {
            dp[j] = max(dp[j - cost[i]] + value[i], dp[j]);
        }
    }
    cout << dp[t];

    return 0;
}
