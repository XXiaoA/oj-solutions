#include <iostream>
using namespace std;

int fa[5001];

int find_f(int x) { return x == fa[x] ? x : fa[x] = find_f(fa[x]); }

int main() {
    int n, m, p, a, b;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    while (m--) {
        cin >> a >> b;
        fa[find_f(a)] = find_f(fa[b]);
    }
    while (p--) {
        cin >> a >> b;
        cout << (find_f(a) == find_f(b) ? "Yes" : "No") << endl;
    }

    return 0;
}
