#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
    int n, i, total = 0;
    std::cin >> n;
    while (n--) {
        std::cin >> i;
        // mod 2 利用了逆元处处求模, 否则要开 long long
        total += i % 2;
    }
    if (total % 2 == 1)
        std::cout << "Alice" << std::endl;
    else
        std::cout << "Bob" << std::endl;

    return 0;
}
