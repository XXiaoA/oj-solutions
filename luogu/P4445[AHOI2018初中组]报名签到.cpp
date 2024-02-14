#include <iostream>
using namespace std;

int main() {
    int n, now, previous = 0;
    // 不开 long long 见祖宗
    long long l = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> now;
        if (previous == 0) {
            previous = now;
            continue;
        }
        if (now > previous) {
            l += now;
        } else {
            l += previous;
        }
        previous = now;
    }

    cout << l << endl;

    return 0;
}
