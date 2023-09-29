#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    std::string str, boy = "boy", girl = "girl";
    std::cin >> str;
    int boy_count = 0, girl_count = 0;

    u_short flag = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str.at(i);
        if (c == '.') {
            continue;
        } else if (boy.find(c) != std::string::npos) {
            flag = boy.find(c) + 1;
            if (i == str.size() - 1 || flag == 3)
                boy_count++;
            else if (str.at(i + 1) == boy.at(flag))
                continue;
            else {
                flag = 0;
                boy_count++;
            }
        } else if (girl.find(c) != std::string::npos) {
            flag = girl.find(c) + 1;
            if (i == str.size() - 1 || flag == 4)
                girl_count++;
            else if (str.at(i + 1) == girl.at(flag))
                continue;
            else {
                flag = 0;
                girl_count++;
            }
        }
    }

    std::cout << boy_count << std::endl << girl_count << std::endl;

    return 0;
}
