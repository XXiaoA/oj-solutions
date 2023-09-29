#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool is_prime(int a) {
    if (a < 2)
        return false;
    for (int i = 2; i * i <= a; ++i)
        if (a % i == 0)
            return false;
    return true;
}

int main() {
    string n;
    int maxn = 0, minn = 101;
    map<char, int> character;
    cin >> n;
    for (const auto &c : n) {
        character[c]++;
    }
    for (const auto &c : n) {
        maxn = max(character[c], maxn);
        minn = min(character[c], minn);
    }
    // for (const auto &character_key : character) {
    //     cout << character_key.first << " " << character_key.second << endl;
    // }
    // cout << maxn << " " << minn << endl;
    if (is_prime(maxn - minn)) {
        cout << "Lucky Word" << endl;
        cout << maxn - minn << endl;
    } else {
        cout << "No Answer" << endl;
        cout << 0 << endl;
    }

    return 0;
}
