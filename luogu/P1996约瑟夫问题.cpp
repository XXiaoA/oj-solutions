#include <cstdio>
#include <deque>
#include <queue>
#include <vector>

void method_1() {
    int n, m;
    std::vector<int> list;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        list.push_back(i);
    }

    int t = m - 1;
    while (!list.empty()) {
        int num = list.at(t);
        printf("%d ", num);
        list.erase(list.cbegin() + t);
        t--;
        // NOTE: 不加 if 会导致 list.size() == 0 之后又算了一遍 t = (t + m) %
        // list.size()
        if (list.size())
            t = (t + m) % list.size();
    }
}

void method_2() {
    int n, m;
    std::queue<int> list;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        list.push(i);
    }

    int t = 1;
    while (!list.empty()) {
        if (t == m) {
            printf("%d ", list.front());
            list.pop();
            t = 1;
        } else {
            t++;
            list.push(list.front());
            list.pop();
        }
    }
}

void method_3() {
    int n, m;
    std::deque<int> list;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        list.push_back(i);
    }

    while (!list.empty()) {
        for (int i = 0; i < m - 1; i++) {
            list.push_back(list.front());
            list.pop_front();
        }
        printf("%d ", list.front());
        list.pop_front();
    }
}

int main(int argc, char *argv[]) {
    method_3();
    return 0;
}
