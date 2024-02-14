#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

// 注意不是删全部最大那个数，例如 1108 删后应该是 108 而不是 110，注意要删前导0,
// 只剩一个0的时候要输出
// 贪心的思想是 局部 最优解推出局部最优解
// 本题思路：
// 即按高位到低位的顺序搜索，若各位数字递增，则删除最后一个数字，否则删除第一个递减区间的首字符，这样删一位便形成了一个新数字串。然后回到数字串首，按上述规则再删下一个数字。重复以上过程
int main() {
    string n;
    int k;
    cin >> n >> k;

again:
    k--;
    unsigned length = n.size();
    for (int i = 0; i < length && k >= 0; i++) {
        if (i != length - 1) {
            if (n.at(i) > n.at(i + 1)) {
                n.erase(i, 1);
                goto again;
            }
        } else {
            n.erase(i, 1);
            goto again;
        }
    }

    // 转换成数字 去掉多余的 0
    cout << stoi(n) << endl;
    return 0;
}
