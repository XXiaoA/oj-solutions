#include <iostream>
using namespace std;

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
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        // cout << qpow(i, p - 2, p) << endl;
    }

    return 0;
}
