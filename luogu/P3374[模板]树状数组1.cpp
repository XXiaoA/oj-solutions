#include <iostream>
#include <vector>
using namespace std;

inline int lowbit(int n) { return n & -n; }

struct Tree {
    vector<int> c;

    // sum 前缀和
    void create(vector<int> &sum) {
        c.push_back(0);
        for (int i = 1; i < sum.size(); i++) {
            c.push_back(sum.at(i) - sum.at(i - lowbit(i)));
        }
    };

    void add(int x, int addend) {
        // 不能等于是因为 c 最前面有一个 0
        while (x < c.size()) {
            c.at(x) += addend;
            x += lowbit(x);
        }
    }

    // a[1]..a[x]的和
    int get_sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += c[x];
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
    vector<int> sum(1);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum.push_back(num + sum.at(i - 1));
    }
    tree.create(sum);

    int t, x, k;
    while (m--) {
        cin >> t >> x >> k;
        if (t == 1) {
            tree.add(x, k);
        } else {
            cout << tree.get_sum(k) - tree.get_sum(x - 1) << endl;
        }
    }

    return 0;
}
