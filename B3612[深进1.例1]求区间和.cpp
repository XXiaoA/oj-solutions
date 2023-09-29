#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int n, m, l, r, num;
    std::vector<int> list = {0};
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> num;
        list.push_back(num + list.at(i - 1));
    }

    std::cin >> m;
    while (m--) {
        std::cin >> l >> r;
        std::cout << list.at(r) - list.at(l - 1) << std::endl;
    }

    return 0;
}
