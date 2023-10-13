#include <cstdio>
#include <iostream>
using namespace std;
using ll = long long;

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

int main() {
#ifdef LOCAL
    freopen("out", "w", stdout);
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int m, a, b, c, op, k, maxa = 0, maxb = 0, maxc = 0;
    a = read(), b = read(), c = read(), m = read();
    // cout << a << " " << b << " " << c << endl;
    while (m--) {
        op = read(), k = read();
        switch (op) {
        case 1:
            if (k > maxa) {
                a -= k - maxa;
                maxa = k;
            }
            break;
        case 2:
            if (k > maxb) {
                b -= k - maxb;
                maxb = k;
            }
            break;
        case 3:
            if (k > maxc) {
                c -= k - maxc;
                maxc = k;
            }
            break;
        }
        // cout << a << " " << b << " " << c << endl;
        cout << (ll)a * b * c << endl;
    }

    return 0;
}
