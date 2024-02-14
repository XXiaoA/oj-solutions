#include <iostream>
using namespace std;

// 同类，猎物，天敌
int fa[100010 * 3];

inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

inline void merge(int a, int b) { fa[find(a)] = find(b); }

int main() {
    int n, k, z, x, y, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n * 3; i++) {
        fa[i] = i;
    }
    while (k--) {
        cin >> z >> x >> y;
        // 注意！不在食物链为假
        if (x > n || y > n) {
            ans++;
            continue;
        }
        if (z == 1) {
            // 如果说是同类，实际上是天敌或猎物则为假
            if (find(x + n) == find(y) || find(x + 2 * n) == find(y)) {
                ans++;
                continue;
            } else {
                // x 的同类是 y 的同类
                merge(x, y);
                // x 的猎物是 y 的猎物
                merge(x + n, y + n);
                // x 的天敌是 y 的天敌
                merge(x + 2 * n, y + 2 * n);
            }
        } else if (z == 2) {
            // x 吃 y
            // x 是 y 的同类或猎物
            if (find(x) == find(y) || find(x + 2 * n) == find(y)) {
                ans++;
                continue;
            } else {
                // x 的同类是 y 的天敌
                merge(x, y + 2 * n);
                // x 的猎物是 y 的同类
                merge(x + n, y);
                // x 的天敌是 y 的猎物
                merge(x + 2 * n, y + n);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
