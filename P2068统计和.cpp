#include <array>
#include <iostream>
using namespace std;

// 不开 ll 见祖宗
using ll = long long;

inline int lowbit(int n) { return n & -n; }

struct {
    array<ll, 100001> c;

    void add(int x, int augend) {
        while (x < c.size()) {
            c.at(x) += augend;
            x += lowbit(x);
        }
    }

    ll get_sum(int x) {
        ll sum = 0;
        while (x > 0) {
            sum += c.at(x);
            x -= lowbit(x);
        }
        return sum;
    }

} tree;

int main() {
    int n, w, a, b;
    char q;
    cin >> n >> w;
    while (w--) {
        cin >> q >> a >> b;
        if (q == 'x') {
            tree.add(a, b);
        } else {
            cout << tree.get_sum(b) - tree.get_sum(a - 1) << endl;
        }
    }

    return 0;
}
