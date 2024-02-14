#include <iostream>
using namespace std;

int n, v, max_used = 0, all_v[30];

void dfs(int used, int index) {
    // cout << index << " " << used << " " << max_used << endl;
    if (used > max_used)
        max_used = used;
    if (used > v || index >= n)
        return;
    dfs(used, index + 1);
    if (used + all_v[index] <= v)
        dfs(used + all_v[index], index + 1);
}

int main() {
    cin >> v >> n;
    for (int i = 0; i < n; i++)
        cin >> all_v[i];
    dfs(0, 0);
    cout << v - max_used << endl;

    return 0;
}
