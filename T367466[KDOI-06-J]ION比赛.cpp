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
    int n, t, cur = 0, a[7] = {0}, b[7] = {0};
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(), b[i] = read();
        cur += 100 / a[i] * b[i];
    }
    t = read();
    if (cur >= t) {
        cout << "Already Au." << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i] || (t - cur) > (100 / a[i] * (a[i] - b[i]))) {
                cout << "NaN" << endl;
            } else {
                cout << (t - cur + 100 / a[i] - 1) / (100 / a[i]) << endl;
            }
        }
    }

    return 0;
}
