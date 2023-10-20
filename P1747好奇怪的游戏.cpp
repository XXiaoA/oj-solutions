#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int read() {
    // clang-format off
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x * w;
    // clang-format on
}

struct point {
    int x, y, step;
};
int vis[100][100];

int dx[] = {1, 2, -2, -1, -2, -1, 1, 2, 2, 2, -2, -2};
int dy[] = {2, 1, 1, 2, -1, -2, -2, -1, 2, -2, 2, -2};
int bfs(int x, int y) {
    queue<point> q;
    int new_x, new_y;
    q.push({x, y, 0});
    vis[x][y] = true;
    while (!q.empty()) {
        point t = q.front();
        q.pop();
        if (t.x == 1 && t.y == 1) {
            return t.step;
        }
        for (int i = 0; i < 12; i++) {
            new_x = t.x + dx[i];
            new_y = t.y + dy[i];
            if (new_x < 1 || new_y < 1 || vis[new_x][new_y])
                continue;
            vis[new_x][new_y] = 1;
            q.push({new_x, new_y, t.step + 1});
        }
    }
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int x, y;
    memset(vis, false, sizeof(vis));
    x = read(), y = read();
    cout << bfs(x, y) << endl;
    memset(vis, false, sizeof(vis));
    x = read(), y = read();
    cout << bfs(x, y) << endl;

    return 0;
}
