#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    // 最不开心的最小时间是 9
    int school, mother, total, most_unhappy = 9, unhappy_date = 0;

    for (int i = 1; i <= 7; i++) {
        cin >> school >> mother;
        total = school + mother;
        if (total > 8) {
            // 注意是最不高兴的一天
            if (unhappy_date == 0 || total > most_unhappy) {
                unhappy_date = i;
                most_unhappy = total;
            }
        }
    }

    cout << unhappy_date;

    return 0;
}
