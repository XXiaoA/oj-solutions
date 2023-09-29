#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void print(vector<int> &nums) {
    for (const auto &value : nums) {
        cout << value << " ";
    }
    cout << endl;
}

// [l, r]
void quick_sort(vector<int> &nums, int l, int r) {
    // 长度为 0
    if (l >= r)
        return;
    int ind_s = 0, ind_e = 0, ind_g = 0;
    int pivot = nums.at(l + (r - l) / 2);
    vector<int> smaller, greater, equal;
    for (int i = l; i <= r; i++) {
        int n = nums.at(i);
        if (n < pivot) {
            ind_s++;
            smaller.push_back(n);
        } else if (n > pivot) {
            ind_g++;
            greater.push_back(n);
        } else {
            ind_e++;
            equal.push_back(n);
        }
    }
    for (int i = 0; i < ind_s; i++)
        nums.at(l + i) = smaller.at(i);

    for (int i = 0; i < ind_e; i++)
        nums.at(l + ind_s + i) = equal.at(i);

    for (int i = 0; i < ind_g; i++)
        nums.at(l + ind_s + ind_e + i) = greater.at(i);

    quick_sort(nums, l, l + ind_s - 1);
    quick_sort(nums, l + ind_s + ind_e, r);
}

void counting_sort(vector<int> &nums) {
    int maxn = nums[0];
    unsigned length = nums.size();
    for (const auto &num : nums) {
        maxn = max(maxn, num);
    }
    int *tmp = new int[maxn];
    for (const auto &num : nums) {
        tmp[num]++;
    }
    do
        while (tmp[maxn]--)
            nums[--length] = maxn;
    while (maxn--);
    delete[] tmp;
}

int main() {
    int n, num;
    vector<int> nums;
    cin >> n;
    while (n--) {
        cin >> num;
        nums.push_back(num);
    }
    // nums = {3, 1, 6, 11, 5, 9, 4, 6};
    // counting_sort(nums);
    quick_sort(nums, 0, (int)nums.size() - 1);
    // sort(nums.begin(), nums.end());
    print(nums);

    return 0;
}
