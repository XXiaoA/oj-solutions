#include <cstdio>
using namespace std;

int main() {
    int q;
    scanf("%d", &q);
    constexpr int MAX = 1e6 + 5;
    int list[MAX];

    for (int i = 0; i < q; i++) {
        int operate, x, y;
        scanf("%d", &operate);
        switch (operate) {
        case 1:
            scanf("%d %d", &x, &y);
            list[y] = list[x];
            list[x] = y;
            break;
        case 2: {
            scanf("%d", &x);
            printf("%d\n", list[x]);
            break;
        }
        case 3:
            scanf("%d", &x);
            y = list[x];
            list[x] = list[y];
            list[y] = 0;
            break;
        }
    }

    return 0;
}
