#include <bits/stdc++.h>
#define int long long
using namespace std;
// total 存的是总共现在有的线段的数量
int n, total;
// all_k 存 k[i] 的值，all_b 存 b[i] 的值
vector<int> all_k, all_b;
// count_k 存 k[i] 的数量，count_b 存 b[i] 的数量
unordered_map<int, int> count_k, count_b;

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int operate, k, b;
        cin >> operate >> k >> b;
        if (operate == 1) {
            total++;
            count_k[k]++;
            count_b[b]++;
            all_k.push_back(k);
            all_b.push_back(b);
        } else if (operate == 2)
            cout << total - count_k[k] << endl;
        else if (operate == 3) {
            // 全部都是平行线
            if (count_k[k] == total && count_b[b] <= 0)
                continue;
            for (auto k1 = all_k.end() - 1, b1 = all_b.end() - 1;
                 k1 >= all_k.begin(); k1--, b1--)
                // 两条线相交
                if (*k1 != k || *b1 == b) {
                    total--;
                    count_k[*k1]--;
                    count_b[*b1]--;
                    swap(*k1, all_k.back());
                    all_k.pop_back();
                    swap(*b1, all_b.back());
                    all_b.pop_back();
                    if (count_k[k] == total && count_b[b] <= 0)
                        continue;
                }
        }
    }
    return 0;
}
