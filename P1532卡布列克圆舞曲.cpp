#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// 十年 oi 一场空，不开 long long 见祖宗
using ll = long long;

ll get_num(ll n, char mode) {
    std::vector<int> digits;
    ll result = 0;
    while (n >= 1) {
        digits.push_back(n % 10);
        n /= 10;
    }
    if (mode == 'g')
        std::sort(digits.begin(), digits.end(), std::greater<int>());
    else
        std::sort(digits.begin(), digits.end(), std::less<int>());
    for (auto digit : digits) {
        result *= 10;
        result += digit;
    }

    return result;
}

void work(ll n) {
    // 第一个 n 也可能算入循环里
    std::vector<ll> nums = {n};
    while (true) {
        ll new_num = get_num(nums.back(), 'g') - get_num(nums.back(), 'l');
        auto it = std::find(nums.cbegin(), nums.cend(), new_num);
        if (it != nums.cend()) {
            for (auto i = it; i != nums.cend(); i++) {
                std::cout << *i << " ";
            }
            std::cout << std::endl;
            break;
        }
        nums.push_back(new_num);
    }
}

int main() {
    int n;
    while (std::cin >> n) {
        work(n);
    }
    return 0;
}
