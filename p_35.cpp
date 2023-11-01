#include <bits/stdc++.h>

constexpr int MAX_PR = 5000000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = 2000000) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 4; i < lim; i += 2)
        is_prime[i] = 0;
    for (int i = 3; i * i < lim; i += 2)
        if (is_prime[i]) {
            for (int j = i * i; j < lim; j += i * 2) {
                is_prime[j] = 0;
            }
        }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sieve();
    int lim, res = 0;
    std::cin >> lim;
    for (int i = 1; i <= lim; i++) {
        if (!is_prime[i]) {
            continue;
        }
        std::string s = std::to_string(i);
        bool ok = true;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            int num = (int)std::stoll(s.substr(n - i, i) + s.substr(0, n - i));
            if (!is_prime[num]) {
                ok = false;
                break;
            }
        }
        res += ok;
    }
    std::cout << "Count: " << res << "\n";
    return 0;
}