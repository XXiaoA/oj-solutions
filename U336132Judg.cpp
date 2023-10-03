#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string result;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> result;
        if (result[0] != 'A') {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
