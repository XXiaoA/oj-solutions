#include <iostream>

int main(int argc, char *argv[]) {
    int n, m = 1;
    std::cin >> n;
    for (int i = 0; i < n - 1; i++) {
        m++;
        m *= 2;
    }

    std::cout << m << std::endl;

    return 0;
}
