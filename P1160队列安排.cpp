#include <iostream>
#include <iterator>
#include <list>

using namespace std;
using iter = list<int>::iterator;

struct {
    iter p;
    bool exist{};
} students[100005];

int main() {
    int n, m, k, p, x;
    list<int> queue;
    cin >> n;
    queue.push_back(1);
    students[1].p = queue.begin();
    students[1].exist = true;

    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        // 0 means left
        students[i].exist = true;
        if (!p) {
            students[i].p = queue.insert(students[k].p, i);
        } else {
            students[i].p = queue.insert(next(students[k].p), i);
        }
    }

    // cout << "queue: ";
    // for (const auto &i : queue) {
    //     cout << i << " ";
    // }
    // cout << endl;

    cin >> m;
    while (m--) {
        cin >> x;
        if (students[x].exist) {
            queue.erase(students[x].p);
            students[x].exist = false;
        }
    }

    for (const auto &i : queue) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
