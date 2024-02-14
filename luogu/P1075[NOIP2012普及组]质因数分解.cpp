#include <iostream>

int main(int argc, char *argv[]) {
    int n;
    std::cin >> n;
    for (int num = 2; num < n; num++) {
        if (n % num == 0) {
            std::cout << n / num;
            break;
        }
    }

    return 0;
}
