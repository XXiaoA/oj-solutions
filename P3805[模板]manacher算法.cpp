#include <iostream>
#include <queue>
using namespace std;

inline int min(int a, int b) { return a <= b ? a : b; }

int main() {
    int n, k, ans = 1, p[1000001 * 2] = {0};
    priority_queue<int> len;
    string s, str = "~|";
    cin >> n >> k >> s;
    for (const auto &s_key : s) {
        str.push_back(s_key);
        str.push_back('|');
    }
    for (int i = 1, r = 0, mid = 0; i < str.size(); i++) {
        if (i <= r)
            p[i] = min(p[mid * 2 - i], r - i + 1);
        while (str[i + p[i]] == str[i - p[i]])
            p[i]++;
        if (i + p[i] > r) {
            r = i + p[i] - 1;
            mid = i;
        }
        if ((p[i] - 1) % 2 == 1) {
            len.push(p[i] - 1);
        }
    }
    // while (!len.empty()) {
    //     cout << len.top() << " ";
    //     len.pop();
    // }
    // cout << endl;
    if (len.size() < k) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < k; i++) {
            ans *= len.top();
            len.pop();
        }
        cout << ans << endl;
    }

    return 0;
}
