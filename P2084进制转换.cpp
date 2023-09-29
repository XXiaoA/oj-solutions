#include <iostream>
#include <string>
using namespace std;

int main() {
    int m;
    string n, ans;
    cin >> m >> n;
    unsigned power = n.size();

    for (const auto &digit : n) {
        power--;
        if (digit == '0')
            continue;
        else {
            ans.append(1, digit);
            ans.append("*");
            ans.append(to_string(m));
            ans.append("^");
            ans.append(to_string(power));
            ans.append("+");
        }
    }

    // 去掉结尾多余的一个 + 号
    // 别写一堆要不要加 + 号的判断，容易错
    ans.pop_back();
    cout << ans << endl;

    return 0;
}
