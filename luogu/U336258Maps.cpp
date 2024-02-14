#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, w, p;
    string map;
    cin >> n;
    while (n--) {
        cin >> w >> p;
        if (p * 2 >= w) {
            cout << -1 << "\n";
            continue;
        }
        map = string(w, '0');
        for (int i = w - 2; i >= 0 && p > 0; i -= 2, p--) {
            map[i + 1] = '1';
            map[i - 1] = '1';
        }
        cout << map << "\n";
    }

    return 0;
}
