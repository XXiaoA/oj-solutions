#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 短除法
string decimal_to_base(int decimal, int base) {
    string result, dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (decimal > 0) {
        char remainder = dict.at(decimal % base);
        result.insert(result.cbegin(), remainder);
        decimal /= base;
    }
    return result;
}

int base_to_decimal(string num, int base) {
    int result = 0, power = 1, n;
    for (auto i = num.size(); i > 0; i--) {
        char c = num.at(i - 1);
        if ('0' <= c && c <= '9')
            n = c - '0';
        else
            n = c - 'A' + 10;
        result += n * power;
        power *= base;
    }
    return result;
}

int main() {
    int n, m;
    string num;
    cin >> n >> num >> m;
    cout << decimal_to_base(base_to_decimal(num, n), m);

    return 0;
}
