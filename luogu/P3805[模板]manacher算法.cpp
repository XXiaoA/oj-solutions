#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int min(int a, int b) { return a <= b ? a : b; }

int main() {
    string n, s = "~|";
    // s[i] 的回文半径
    vector<int> p(11000002 * 2, 0);
    int ans;
    cin >> n;
    // aba -> ~|a|b|a|
    for (const auto &n_key : n) {
        s.push_back(n_key);
        s.push_back('|');
    }
    // r 表示我们经过的，最靠右边的点
    // mid 表示这个最靠右的点是由哪一个对称轴转移过来的
    for (int i = 1, r = 0, mid = 0; i < s.size(); i++) {
        // 如果 i 在右边界内
        if (i <= r)
            // i 关于 mid 的对称点为 mid * 2 - i
            // 能确定的范围右侧不大于
            // r，即 p[i] + i - 1 <= r => p[i] <= r - i + 1
            p[i] = min(p[mid * 2 - i], r - i + 1);
        // 暴力向两边拓展
        // s[0] == '~' 故不会越界
        while (s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if (p[i] + i > r) {
            r = p[i] + i - 1;
            mid = i;
        }
        if (p[i] > ans)
            ans = p[i];
    }

    // n[i] 的回文长度 == s[i] 的回文半径 + 1
    cout << ans - 1 << endl;

    return 0;
}
