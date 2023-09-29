#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};
int ans[401][401], visited[401][401];
int n, m, x, y;

void bfs(int x, int y) {
    memset(ans, -1, sizeof(ans)); // 无法达到为 -1
    queue<pair<int, int>> q;
    q.emplace(x, y);
    ans[x][y] = 0;
    visited[x][y] = 1;
    while (!q.empty()) {
        auto front = q.front();
        int x = front.first, y = front.second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x > n || new_x < 1 || new_y > m || new_y < 1)
                continue;
            if (visited[new_x][new_y])
                continue;
            q.emplace(new_x, new_y);
            visited[new_x][new_y] = 1;
            ans[new_x][new_y] = ans[x][y] + 1;
        }
    }
}

int main() {
    cin >> n >> m >> x >> y;
    bfs(x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << ans[i][j] << " ";
            printf("%-5d", ans[i][j]); // 坑！
        }
        cout << endl;
    }

    return 0;
}
