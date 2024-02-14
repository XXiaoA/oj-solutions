#include <bitset>
#include <iostream>
using namespace std;

bitset<100000010> is_prime;
int prime[6000010], cnt = 0;

// 埃氏筛
void get_prime(int n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
            // for (int j = i; j * i <= n; j++)
            //     is_prime[j * i] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            prime[++cnt] = i;
    }
}

// 欧式筛
void get_prime2(int n) {
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    int n, q, a;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    // get_prime(n);
    get_prime2(n);
    while (q--) {
        cin >> a;
        cout << prime[a] << endl;
    }

    return 0;
}
