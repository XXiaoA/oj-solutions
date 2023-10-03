#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string num;
    vector<string> nums;
    cin >> n;
    while (n--) {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end(),
         [](string a, string b) { return a + b > b + a; });
    for (const auto &num : nums) {
        cout << num;
    }
    cout << endl;

    return 0;
}
