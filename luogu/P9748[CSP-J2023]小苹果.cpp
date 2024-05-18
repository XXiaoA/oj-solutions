#include <cmath>
#include <iostream>
using namespace std;

int read() {
    // clang-format off
    int x = 0, w = 1; char ch = 0;
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + (ch - '0'); ch = getchar(); }
    return x * w;
    // clang-format on
}

int main() {
    ios::sync_with_stdio(false);
    int n, ans = 0, count = 0;
    n = read();
    while (n) {
        count++;
        if (n % 3 == 1 && ans == 0)
            ans = count;
        n -= ceil(n / 3.0);
    }
    cout << count << " " << ans;

    return 0;
}
