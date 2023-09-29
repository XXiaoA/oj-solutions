#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    cin >> s;
    for (int i = s.size(); i > 0; i--) {
        cout << s[i - 1];
    }

    return 0;
}
