#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int l, r, c;
} interval[1010];

int main() {
    int n, filled[30010] = {0}, ans = 0, sum;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> interval[i].l >> interval[i].r >> interval[i].c;
    }
    sort(interval + 1, interval + n + 1, [](Interval x, Interval y) {
        return x.r < y.r;
    }); // 右端点从小到大排序
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = interval[i].l; j <= interval[i].r; j++) {
            if (filled[j])
                sum++;
        }
        for (int j = interval[i].r; j >= interval[i].l; j--) {
            if (sum >= interval[i].c)
                break;
            if (!filled[j]) {
                sum++;
                ans++;
                filled[j] = 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
