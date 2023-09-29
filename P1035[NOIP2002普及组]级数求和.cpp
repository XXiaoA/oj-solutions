#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, i = 0;
    vector<double> list = {0};
    cin >> k;
    // 一点点前缀和思想，可以直接加，不保存的（
    while (list.at(i) <= k) {
        i++;
        list.push_back(list.at(i - 1) + 1.0 / i);
    }
    cout << i << endl;

    return 0;
}
