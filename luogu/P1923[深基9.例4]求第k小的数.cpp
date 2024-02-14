#include <iostream>
#include <vector>
using namespace std;

int k;
vector<int> nums;

// [l, r]
void qsort(int l, int r) {
    int i = l, j = r, pivot = nums[l + (r - l) / 2];
    do {
        while (nums[j] > pivot)
            j--;
        while (nums[i] < pivot)
            i++;
        if (i <= j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (k <= j)
        qsort(l, j);
    else if (k >= i)
        qsort(i, r);
    else {
        cout << nums[j + 1] << endl;
        return;
    }
}

int main() {
    int n, a;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.push_back(a);
    }
    qsort(0, n - 1);

    return 0;
}
