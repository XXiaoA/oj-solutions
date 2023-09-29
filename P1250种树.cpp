#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int b, e, t;
} interval[5010];

int main() {
    int n, h, planted[30010] = {0}, ans = 0, sum;
    cin >> n >> h;
    for (int i = 1; i <= h; i++) {
        cin >> interval[i].b >> interval[i].e >> interval[i].t;
    }
    sort(interval + 1, interval + h + 1, [](Interval x, Interval y) {
        return x.e < y.e;
    }); // 右端点从小到大排序
    for (int i = 1; i <= h; i++) {
        sum = 0;
        for (int j = interval[i].b; j <= interval[i].e; j++) {
            if (planted[j])
                sum++;
        }
        for (int j = interval[i].e; j >= interval[i].b; j--) {
            if (sum >= interval[i].t)
                break;
            if (!planted[j]) {
                sum++;
                ans++;
                planted[j] = 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
