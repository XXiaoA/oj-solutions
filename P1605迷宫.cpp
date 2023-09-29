#include <iostream>
using namespace std;

int n, m, t, sx, sy, fx, fy, ans = 0;
// 1： 障碍
int **map = new int *[n];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check(int x, int y) {
    if (x > n || x < 1 || y > m || y < 1)
        return false;
    if (map[x - 1][y - 1])
        return false;
    return true;
}

// NOLINTNEXTLINE
void dfs(int x, int y) {
    if (!check(x, y))
        return;
    // cout << x << " " << y << endl;
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    // 注意每个方格最多经过一次
    for (int i = 0; i < 4; i++) {
        map[x - 1][y - 1] = 1;
        dfs(x + dx[i], y + dy[i]);
        // 注意这要改回来，不影响其他分支
        map[x - 1][y - 1] = 0;
    }
}

int main() {
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;

    for (int i = 0; i < n; i++) {
        map[i] = new int[m];
    }

    int tx, ty;
    while (t--) {
        cin >> tx >> ty;
        map[tx - 1][ty - 1] = 1;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         std::cout << map[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    dfs(sx, sy);
    cout << ans << endl;

    for (int i = 0; i < n; i++) {
        delete[] map[i];
    }
    delete[] map;

    return 0;
}
