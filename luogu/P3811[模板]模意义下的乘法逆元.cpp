#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int x, y;
void exgcd(int a, int b) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b);
    int t = x;
    x = y;
    y = t - a / b * y;
}

int qpow(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cout.tie(nullptr), cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    // for (int i = 1; i <= n; i++) {
    //     exgcd(i, p);
    //     cout << (x % p + p) % p << endl;

    //     // cout << qpow(i, p - 2, p) << endl;
    // }

    vector<ll> inv = {0, 1};
    cout << 1 << endl;
    for (int i = 2; i <= n; i++) {
        inv.push_back((ll)p - p / i * inv[p % i] % p);
        cout << inv.back() << '\n';
        // cout << inv.back() << endl;
    }

    return 0;
}
