#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main() {
    int n, k, num;
    set<int> nums;
    cin >> n >> k;
    while (n--) {
        cin >> num;
        nums.insert(num);
    }
    auto it = nums.begin();
    advance(it, k - 1);
    if (k < nums.size())
        cout << *it << endl;
    else
        cout << "NO RESULT" << endl;

    return 0;
}
