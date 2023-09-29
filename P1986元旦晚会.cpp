#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int b, e, t;
} interval[5010];

int main() {
    int n, m, has_mike[30010] = {0}, ans = 0, sum;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> interval[i].b >> interval[i].e >> interval[i].t;
    }
    sort(interval + 1, interval + m + 1, [](Interval x, Interval y) {
        return x.e < y.e;
    }); // 右端点从小到大排序
    for (int i = 1; i <= m; i++) {
        sum = 0;
        for (int j = interval[i].b; j <= interval[i].e; j++) {
            if (has_mike[j])
                sum++;
        }
        for (int j = interval[i].e; j >= interval[i].b; j--) {
            if (sum >= interval[i].t)
                break;
            if (!has_mike[j]) {
                sum++;
                ans++;
                has_mike[j] = 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
