/**
 * @file
 * @brief https://www.luogu.com.cn/problem/P1042
 * 注意：
 *      - 可能第一个输入就是 E （忽略其后内容）
 *      - 结束一局的条件：一方得分大于等于 11/21 且 双方分差大于等于两分
 */

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    char input;
    vector<char> score;
    while (scanf("%c", &input) && input != 'E') {
        if (input == 'W' || input == 'L')
            score.push_back(input);
    }
    score.push_back('E');
    int w = 0, l = 0;
    for (auto ch : score) {
        if (ch == 'W')
            w++;
        if (ch == 'L')
            l++;
        if (ch == 'E') {
            printf("%d:%d\n", w, l);
        }
        if ((w >= 11 || l >= 11) && abs(w - l) >= 2) {
            w = 0, l = 0;
        }
    }
    printf("\n");
    w = 0, l = 0;
    for (auto ch : score) {
        if (ch == 'W')
            w++;
        if (ch == 'L')
            l++;
        if (ch == 'E') {
            printf("%d:%d\n", w, l);
        }
        if ((w >= 21 || l >= 21) && abs(w - l) >= 2) {
            printf("%d:%d\n", w, l);
            w = 0, l = 0;
        }
    }

    return 0;
}
