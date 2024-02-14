#include <iostream>
using namespace std;
using ll = long long;

int read() {
    // clang-format off
    int x = 0, f = 1; char c = 0;
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
    // clang-format on
}

int n, m, mod;
int a[1000005];

struct Segment_Tree {
    ll sum, add, mul;
    int l, r;
} s[1000005 * 4];

void pushdown(int pos) {
    s[pos << 1].sum = (s[pos << 1].sum * s[pos].mul +
                       s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1)) %
                      mod;
    s[pos << 1 | 1].sum =
        (s[pos << 1 | 1].sum * s[pos].mul +
         s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1)) %
        mod;

    s[pos << 1].mul = (s[pos << 1].mul * s[pos].mul) % mod;
    s[pos << 1 | 1].mul = (s[pos << 1 | 1].mul * s[pos].mul) % mod;

    s[pos << 1].add = (s[pos << 1].add * s[pos].mul + s[pos].add) % mod;
    s[pos << 1 | 1].add = (s[pos << 1 | 1].add * s[pos].mul + s[pos].add) % mod;

    s[pos].add = 0;
    s[pos].mul = 1;
    return;
}

void build(int pos, int l, int r) {
    s[pos].l = l;
    s[pos].r = r;
    s[pos].mul = 1;

    if (l == r) {
        s[pos].sum = a[l] % mod;
        return;
    }

    int mid = (l + r) >> 1;
    build(pos << 1, l, mid);
    build(pos << 1 | 1, mid + 1, r);
    s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % mod;
    return;
}

void mul(int pos, int x, int y, int k) {
    if (x <= s[pos].l && s[pos].r <= y) {
        s[pos].add = (s[pos].add * k) % mod;
        s[pos].mul = (s[pos].mul * k) % mod;
        s[pos].sum = (s[pos].sum * k) % mod;
        return;
    }

    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid)
        mul(pos << 1, x, y, k);
    if (y > mid)
        mul(pos << 1 | 1, x, y, k);
    s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % mod;
    return;
}

void add(int pos, int x, int y, int k) {
    if (x <= s[pos].l && s[pos].r <= y) {
        s[pos].add = (s[pos].add + k) % mod;
        s[pos].sum = (s[pos].sum + k * (s[pos].r - s[pos].l + 1)) % mod;
        return;
    }

    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid)
        add(pos << 1, x, y, k);
    if (y > mid)
        add(pos << 1 | 1, x, y, k);
    s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % mod;
    return;
}

ll ask(int pos, int x, int y) {
    if (x <= s[pos].l && s[pos].r <= y) {
        return s[pos].sum;
    }

    pushdown(pos);
    ll val = 0;
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid)
        val = (val + ask(pos << 1, x, y)) % mod;
    if (y > mid)
        val = (val + ask(pos << 1 | 1, x, y)) % mod;
    return val;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    n = read(), m = read(), mod = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, x, y, k;
        opt = read(), x = read(), y = read();
        if (opt == 1) {
            k = read();
            mul(1, x, y, k);
        }
        if (opt == 2) {
            k = read();
            add(1, x, y, k);
        }
        if (opt == 3) {
            cout << ask(1, x, y) << "\n";
        }
    }

    return 0;
}
