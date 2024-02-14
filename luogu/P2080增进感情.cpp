#include <iostream>
#include <vector>
using namespace std;

int ans = 300, n, v, ai, bi;
vector<int> a, b;

inline int abs(int x) { return x >= 0 ? x : -x; }

// x, y 分别是小明和小红的好感度
void dfs(int x, int y, int k) {
    if (k > n || ans == 0) // 剪枝
        return;
    if (x + y > v && abs(x - y) < ans) {
        ans = abs(x - y);
    }
    dfs(x + a[k], y + b[k], k + 1);
    dfs(x, y, k + 1);
}

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i++) {
        cin >> ai >> bi;
        a.push_back(ai);
        b.push_back(bi);
    }
    dfs(0, 0, 0);
    if (ans == 300)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
