#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
bitset<100000001> is_prime;

int main() {
    int n, ans = 0;
    cin >> n;

    is_prime.set();
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;

    for (int i = 2; i <= n; i++)
        if (is_prime[i])
            ans++;

    cout << ans << endl;

    return 0;
}
