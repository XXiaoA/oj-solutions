#include <iostream>
using namespace std;

int main() {
    int n, ans = -1, i;
    cin >> n;
    while (n--) {
        cin >> i;
        if (ans == -1)
            ans = i;
        if (i < ans)
            ans = i;
    }

    cout << ans << endl;

    return 0;
}
