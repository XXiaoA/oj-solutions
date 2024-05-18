#include <iostream>
#include <stack>
using namespace std;

stack<int> st; // 存下标
unsigned long long a[1000005];

int main() {
    ios::sync_with_stdio(false);
    int n = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (!st.empty() && (a[i] >= a[st.top()])) {
            ans ^= st.top();
            st.pop();
        }
        st.push(i);
        ans ^= i;
        cout << ans << endl;
    }
    return 0;
}
