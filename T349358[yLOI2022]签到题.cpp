#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int digital = 0, lower = 0, upper = 0;
    cin >> s;

    for (char i : s) {
        if (48 <= i and i <= 57) {
            digital++;
        } else if (97 <= i and i <= 122) {
            lower++;
        } else if (65 <= i and i <= 90) {
            upper++;
        }
    }
    printf("%d %d %d", digital, lower, upper);

    return 0;
}
