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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, a[2000001], i;
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (i = n; i > 0; i -= 2) {
        cout << ((n - i + 1) % 2 == 0 ? a[i] : !a[i]) << " ";
    }
    i = i == 0 ? 1 : 2;
    for (int j = i; j < n; j += 2) {
        cout << ((n - j + 1) % 2 == 0 ? a[j] : !a[j]) << " ";
    }

    return 0;
}
