#include <iostream>
using namespace std;

int read() {
    // clang-format off
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x * w;
    // clang-format on
}

int dfs(int n, int k, int cur) {
    if (k == 1)
        return 1;
    int sum = 0;
    for (int i = cur; i <= n / k; i++) {
        sum += dfs(n - i, k - 1, i);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    n = read(), k = read();
    cout << dfs(n, k, 1) << endl;

    return 0;
}
