#include <iostream>
using namespace std;

// 分差数组
int tree[5000001] = {0}, n, p;

inline int lowbit(int x) { return x & -x; }

// 维护一个分差列表
void build(const int array[]) {
    for (int i = 1; i <= n; i++) {
        tree[i] = array[i] - array[i - lowbit(i)];
    }
}

void add(int x, int addend) {
    while (x <= n) {
        tree[x] += addend;
        x += lowbit(x);
    }
}

void add(int x, int y, int z) {
    add(x, z);
    add(y + 1, -z);
}

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += tree[x];
        x -= lowbit(x);
    }
    return sum;
}

int main() {
    cin >> n >> p;
    int num, sums[5000001] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sums[i] = num;
    }
    build(sums);

    int x, y, z;
    while (p--) {
        cin >> x >> y >> z;
        add(x, y, z);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << tree[i] << " ";
    // }
    // cout << endl;

    int temp, minn = query(1);
    for (int i = 2; i <= n; i++) {
        temp = query(i);
        minn = temp < minn ? temp : minn;
    }
    cout << minn << endl;

    return 0;
}
