#include <iostream>
using namespace std;
using ll = long long;

int read() {
    int x = 0, f = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

struct tree {
    int l, r;
    ll pre, add;
} t[4 * 1000005];
int a[1000005];

inline ll ls(int p) { // left son
    return p << 1;
}
inline ll rs(int p) {  // right son
    return p << 1 | 1; // p * 2 + 1
}

void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    if (l == r) {
        t[p].pre = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;
}

void spread(int p) {
    if (t[p].add) {
        t[ls(p)].pre += t[p].add * (t[ls(p)].r - t[ls(p)].l + 1);
        t[rs(p)].pre += t[p].add * (t[rs(p)].r - t[rs(p)].l + 1);
        t[ls(p)].add += t[p].add;
        t[rs(p)].add += t[p].add;
        t[p].add = 0; // 下放后清零
    }
}

void change(int p, int x, int y, int z) {
    if (x <= t[p].l && y >= t[p].r) {
        t[p].pre += z * (t[p].r - t[p].l + 1);
        t[p].add += z;
        return;
    }
    spread(p);
    int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
    if (x <= mid)
        change(ls(p), x, y, z);
    if (y > mid)
        change(rs(p), x, y, z);
    t[p].pre = t[ls(p)].pre + t[rs(p)].pre;
}

ll ask(int p, int x, int y) {
    if (x <= t[p].l && y >= t[p].r) {
        return t[p].pre;
    }
    spread(p);
    int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
    ll ans = 0;
    if (x <= mid)
        ans += ask(ls(p), x, y);
    if (y > mid)
        ans += ask(rs(p), x, y);
    return ans;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    build(1, 1, n);
    while (m--) {
        int q, x, y, z;
        q = read();
        if (q == 1) {
            x = read(), y = read(), z = read();
            change(1, x, y, z);
        } else {
            x = read(), y = read();
            cout << ask(1, x, y) << "\n";
        }
    }

    return 0;
}
