#include <iostream>
#include <vector>
using namespace std;

inline int lowbit(int n) { return n & -n; }

struct Tree {
    vector<int> c;

    void create(vector<int> &sum) {
        c.push_back(0);
        for (int i = 1; i < sum.size(); i++) {
            c.push_back(sum.at(i) - sum.at(i - lowbit(i)));
        }
    }

    void add(int x, int augend) {
        while (x < c.size()) {
            c.at(x) += augend;
            x += lowbit(x);
        }
    }

    int get_sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += c.at(x);
            x -= lowbit(x);
        }
        return sum;
    }

    void print() {
        cout << "Tree: ";
        for (int i = 1; i < c.size(); i++) {
            cout << c.at(i) << " ";
        }
        cout << endl;
    }

} tree;

int main() {
    int n, m, num;
    // 维护一个分差列表
    // a[i] = b[1] + ... + b[i], 分差的前缀和等于原本这个数
    vector<int> sum(1);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum.push_back(num);
    }
    tree.create(sum);

    int t, x, y, k;
    while (m--) {
        cin >> t;
        if (t == 1) {
            cin >> x >> y >> k;
            tree.add(x, k);
            tree.add(y + 1, -k);
        } else {
            cin >> x;
            cout << tree.get_sum(x) << endl;
        }
    }
    return 0;
}
