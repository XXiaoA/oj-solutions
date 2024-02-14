#include <iostream>
using namespace std;

int main() {
    static const int MAXN = 1e5 + 5;
    int n, k, nums[MAXN], que[MAXN];
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    int head = 0, tail = 0;
    for (int i = 1; i < k; i++) {
        while (head <= tail && nums[que[tail]] >= nums[i])
            tail--;
        que[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && nums[que[tail]] >= nums[i])
            tail--;
        que[++tail] = i;
        while (que[head] <= i - k)
            head++;
        cout << nums[que[head]] << " ";
    }
    cout << endl;

    head = 0, tail = 0;
    for (int i = 1; i < k; i++) {
        while (head <= tail && nums[que[tail]] <= nums[i])
            tail--;
        que[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && nums[que[tail]] <= nums[i])
            tail--;
        que[++tail] = i;
        while (que[head] <= i - k)
            head++;
        cout << nums[que[head]] << " ";
    }
    cout << endl;

    return 0;
}
