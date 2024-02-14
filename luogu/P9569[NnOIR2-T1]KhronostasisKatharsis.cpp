#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct b {
    int i, d;
};

int main() {
    int n, T, v, t, ans;
    vector<b> balloon;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> v >> t;
        balloon.push_back({i, v * (T - t)});
    }
    sort(balloon.begin(), balloon.end(), [](b x, b y) { return x.d > y.d; });
    // 注意求最大中编号最小的那个
    ans = balloon.at(0).i;
    int maxn = balloon.at(0).d;
    for (int i = 0; i < n && balloon.at(i).d == maxn; i++) {
        ans = min(ans, balloon.at(i).i);
    }
    cout << ans << endl;

    return 0;
}
