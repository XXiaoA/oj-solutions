#include <iostream>
#include <vector>
using namespace std;

const int mod = 100003;
vector<vector<int>> ha(mod);
int len = 0;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

bool check(int value) {
    int pos = (mod + value % mod) % mod;
    len = max(len, pos);
    for (int i : ha[pos])
        if (i == value)
            return false;
    ha[pos].push_back(value);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, a;
    // cin >> t;
    t = read();
    while (t--) {
        // cin >> n;
        n = read();
        for (int i = 0; i <= len; i++)
            ha[i].clear();
        len = 0;
        for (int i = 0; i < n; i++) {
            // cin >> a;
            a = read();
            if (check(a))
                cout << a << " ";
        }
        cout << '\n';
    }
    return 0;
}
