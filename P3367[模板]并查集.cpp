#include <iostream>
#include <vector>
using namespace std;

vector<int> fa = {0};

// 路径压缩
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    int n, m, z, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fa.push_back(i);
    }

    while (m--) {
        cin >> z;
        switch (z) {
        case 1:
            cin >> x >> y;
            fa[find(x)] = find(y);
            break;
        case 2:
            cin >> x >> y;
            cout << (find(x) == find(y) ? "Y" : "N") << endl;
            break;
        }
    }

    return 0;
}
