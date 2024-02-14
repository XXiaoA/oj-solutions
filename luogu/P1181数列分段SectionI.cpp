#include <iostream>
using namespace std;

int main() {
    int n, m, i, cnt = 0, temp = 0;
    cin >> n >> m;
    while (n--) {
        cin >> i;
        temp += i;
        if (temp > m) {
            cnt++;
            temp = i;
        }
    }
    cnt++;

    cout << cnt;

    return 0;
}
