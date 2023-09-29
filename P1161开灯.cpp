#include <array>
#include <cmath>
#include <iostream>

// 对于 100% 的数据，满足T≤2000000T≤2000000
#define MAXN 2000005
using namespace std;

int main() {
    int n, t;
    double a;
    array<int, MAXN> is_on{};
    cin >> n;
    while (n--) {
        cin >> a >> t;
        for (int i = 1; i <= t; i++) {
            // ⌊k⌋ 向下取整 floor, ⌈x⌉ 向上取整 ceil
            int light = floor(a * i);
            is_on.at(light) = (is_on.at(light) + 1) % 2;
        }
    }

    for (int i = 1; i < MAXN; i++) {
        if (is_on.at(i) == 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
