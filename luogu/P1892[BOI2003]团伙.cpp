#include <iostream>
using namespace std;

// 种类并查集, 朋友和敌人
int fa[1001 * 2];

inline int find_f(int x) { return x == fa[x] ? x : fa[x] = find_f(fa[x]); }

inline void merge_set(int a, int b) { fa[find_f(a)] = find_f(b); }

int main() {
    int n, m, p, q, ans = 0;
    char r;
    cin >> n >> m;

    for (int i = 1; i <= n * 2; i++) {
        fa[i] = i;
    }
    while (m--) {
        cin >> r >> p >> q;
        if (r == 'F') {
            merge_set(p, q);
        } else if (r == 'E') {
            // p 的敌人是 q 的朋友
            merge_set(p + n, q);
            // q 的敌人是 p 的朋友
            merge_set(q + n, p);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (fa[i] == i)
            ans++;
    }
    cout << ans << endl;

    return 0;
}
