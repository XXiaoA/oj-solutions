#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    int n, bottle;
    std::vector<int> table;
    std::cin >> n;
    while (n--) {
        std::cin >> bottle;
        table.push_back(bottle);
    }
    auto first = std::find(table.cbegin(), table.cend(), 1);
    if (first == table.cend()) {
        std::cout << 0 << std::endl;
    } else {
        int target = 1;
        auto last =
            std::find_end(table.cbegin(), table.cend(), &target, &target + 1);
        std::cout << std::distance(first, last) + 1;
    }

    return 0;
}
