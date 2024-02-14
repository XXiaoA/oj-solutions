#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

const int MAXN = 100001;
int n;

inline int lowbit(int n) { return n & -n; }

struct Cow {
    int i, hight;
} cow[MAXN];

array<int, MAXN> tree;

void add(int x, int augend) {
    while (x < n) {
        tree.at(x) += augend;
        x += lowbit(x);
    }
}

int get_sum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree.at(x);
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    int num, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        cow[i].hight = num;
        cow[i].i = i;
    }
    sort(cow + 1, cow + 1 + n, [](Cow x, Cow y) { return x.hight > y.hight; });
    for (int i = 1; i <= n; i++) {
        add(cow[i].i, 1);
        int l = get_sum(cow[i].i - 1);
        int r = i - 1 - l;
        if (max(l, r) > 2 * min(l, r))
            count++;
    }
    cout << count << endl;

    return 0;
}
