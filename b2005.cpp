#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    char c;
    cin >> c;

    for (int i = 1; i < 4; i++) {
        for (int k = 2; k > i - 1; k--) {
            cout << " ";
        }
        for (int j = 0; j < i * 2 - 1; j++) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
