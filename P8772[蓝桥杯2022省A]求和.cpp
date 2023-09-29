#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, num;
    long long count = 0;
    vector<long long> total = {0};
    vector<int> list = {0};
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        total.push_back(num + total.at(i));
        list.push_back(num);
    }

    auto size = list.size();
    for (int i = 1; i < size; i++) {
        count += list.at(i) * (total.at(size - 1) - total.at(i));
    }

    cout << count << endl;

    return 0;
}
