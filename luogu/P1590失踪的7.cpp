#include <cmath>
#include <iostream>
#include <vector>

int find_7(std::vector<int> digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits.at(i) == 7) {
            return i;
        }
    }
    return -1;
}

void work_1(unsigned num) {
    int count = 0;
    for (unsigned i = 1; i <= num; i++) {
        unsigned n = i;
        std::vector<int> digits;
        while (n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int pos_7 = find_7(digits);
        if (pos_7 != -1) {
            n += std::pow(10, pos_7);
        } else
            count++;
    }
    std::cout << count << std::endl;
}

void work_2(unsigned num) {
    unsigned count = 0;
    for (unsigned i = 1; i <= num; i++) {
        unsigned n = i;
        while (n) {
            if (n % 10 == 7) {
                count++;
                break;
            }
            n /= 10;
        }
    }
    std::cout << num - count << std::endl;
}

void work_3(unsigned num) {
    int digit, power = 0;
    unsigned result = 0;
    while (num) {
        digit = num % 10;
        if (digit < 7)
            result += digit * std::pow(9, power);
        else
            result += (digit - 1) * std::pow(9, power);
        num /= 10;
        power++;
    }
    std::cout << result << std::endl;
}

int main() {
    int t;
    unsigned n;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        // work_1(n);
        // work_2(n);
        work_3(n);
    }

    return 0;
}
