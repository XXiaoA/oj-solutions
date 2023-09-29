#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct Gold {
    int m;
    int v;
    double r;
} golds[100];

int main() {
    int n, t;
    double ans;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> golds[i].m >> golds[i].v;
        golds[i].r = (double)golds[i].v / golds[i].m;
    }
    sort(golds, golds + n, [](Gold x, Gold y) { return x.r > y.r; });
    for (int i = 0; i < n && t != 0; i++) {
        if (t >= golds[i].m) {
            t -= golds[i].m;
            ans += golds[i].v;
        } else {
            ans += golds[i].r * t;
            break;
        }
    }

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}
