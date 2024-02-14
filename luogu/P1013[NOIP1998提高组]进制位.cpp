#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n;
unordered_map<char, int> ans;
string s[10][10];

// 检查 （x, y） 的数是否正确
inline bool check(int x, int y) {
    int sum = ans[s[1][x][0]] + ans[s[1][y][0]]; // 十进制下的正确答案
    string cur_str = s[x][y];
    int num;
    if (cur_str.size() == 1) {
        num = ans[cur_str[0]];
    } else {
        num = ans[cur_str[1]] + (n - 1);
    }
    // cout << x << " " << y << " " << sum << " " << num << " " << endl;
    return sum == num;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    for (int i = 2; i <= n; i++) {
        ans[s[1][i][0]] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            if (s[i][j].size() >= 2) {
                ans[s[1][j][0]]++;
            }
        }
    }
    // for (int i = 2; i <= n; i++)
    //     cout << s[1][i] << "=" << ans[s[1][i][0]] << " ";
    // cout << endl;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= n; j++)
            if (!check(i, j)) {
                cout << "ERROR!" << endl;
                return 0;
            }
    for (int i = 2; i <= n; i++)
        cout << s[1][i] << "=" << ans[s[1][i][0]] << " ";
    cout << endl << n - 1 << endl;
    return 0;
}
