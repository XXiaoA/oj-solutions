#include <iostream>
#include <queue>
#include <utility>
using namespace std;

// first 楼层; second 按的次数
// 不用这个会导致往上往下的时候计算成按两次
using storey = pair<int, int>;

int main() {
    int n, a, b, k[201], visited[201] = {0}, ans = 0;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    queue<storey> que;
    storey current;
    que.emplace(a, 0);
    while (!que.empty()) {
        current = que.front();
        que.pop();
        if (current.first == b) {
            break;
        }

        storey up = {current.first + k[current.first], current.second + 1};
        storey down = {current.first - k[current.first], current.second + 1};
        // 注意检查是否访问过
        if (up.first <= n && !visited[up.first]) {
            que.push(up);
            visited[up.first] = 1;
        }
        if (down.first >= 1 && !visited[down.first]) {
            que.push(down);
            visited[down.first] = 1;
        }
    }
    cout << (current.first == b ? current.second : -1) << endl;

    return 0;
}
