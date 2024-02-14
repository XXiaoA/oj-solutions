#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct People {
    int time, index;
} people[1001];

int main() {
    int n, t;
    double average = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> people[i].time;
        people[i].index = i;
    }
    sort(people + 1, people + 1 + n,
         [](People x, People y) { return x.time < y.time; });

    for (int i = 1; i <= n; i++) {
        average += (double)people[i].time * (n - i) / n;
        cout << people[i].index << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << average << endl;

    return 0;
}
