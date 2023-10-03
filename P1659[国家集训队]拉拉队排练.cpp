#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int mod = 19930726;
const int N = 1000005;

ll qpow(ll base, int n) {
    if (base == 1 | n == 0)
        return 1;
    ll ans = 1;
    while (n) {
        if (n & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        n >>= 1;
    }
    return ans;
}

inline int min(int a, int b) { return a <= b ? a : b; }

int main() {
    ll n, k, ans = 1;
    vector<int> p(2 * N, 0), cnt(N, 0);
    string s, str = "~|";
    cin >> n >> k >> s;
    for (const auto &s_key : s) {
        str.push_back(s_key);
        str.push_back('|');
    }
    for (int i = 1, r = 0, mid = 0; i < str.size(); i++) {
        if (i <= r)
            p[i] = min(p[mid * 2 - i], r - i + 1);
        while (str[i - p[i]] == str[i + p[i]])
            p[i]++;
        if (p[i] + i > r) {
            r = p[i] + i - 1;
            mid = i;
        }
        if ((p[i] - 1) % 2) {
            cnt[p[i] - 1]++;
        }
    }

    int sum = 0;
    if (n % 2 == 0)
        n--;
    for (int i = n; i >= 1; i -= 2) {
        sum += cnt[i];
        if (sum > k) {
            ans = ans * qpow(i, k) % mod;
            break;
        } else {
            ans = ans * qpow(i, sum) % mod;
            k -= sum;
        }
    }
    if (sum < k)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
