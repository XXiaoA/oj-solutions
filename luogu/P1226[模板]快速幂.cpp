#include <iostream>
using namespace std;

using ll = long long;

ll quick_pow(int a, int b, int p) {
    ll ans = 1, base = a;
    while (b > 0) {
        if (b & 1)
            ans = ans * base % p;
        base = base * base % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << quick_pow(a, b, p) << endl;

    return 0;
}
