#include <iostream>

int main(int argc, char *argv[]) {
    int scores[5], sum = 0;
    std::cin >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4];
    for (auto score : scores) {
        sum += score;
    }
    if (sum < 100)
        std::cout << "Gray";
    else if (sum < 120)
        std::cout << "Blue";
    else if (sum < 170)
        std::cout << "Green";
    else if (sum < 230)
        std::cout << "Orange";
    else
        std::cout << "Red";

    return 0;
}
