#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    char in;
    string input;
    bool flag = false; // 是否有解
    int a = 0;         // 记录融化的冰川
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> in;
        input += in;
        if (in == 'N') {
            a++;
            flag = true;
        } else if (in == 'Y' && a == 0) { // 特判!!! 第一个 Y 直接无解
            break;
        }
    }
    if (!flag || a > n) {
        cout << "No solution";
    } else {
        a = 0;
        for (const auto &input_key : input) {
            if (input_key == 'N') {
                a++;
                cout << a << " ";
            } else {
                cout << 1 << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
