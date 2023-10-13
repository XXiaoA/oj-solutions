#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    replace(s.begin(), s.end(), '_', '-');
    cout << "solution-" << s << endl;

    return 0;
}
