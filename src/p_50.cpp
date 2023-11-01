#include <bits/stdc++.h>

constexpr int MAX_PR = 50000000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = 20000000) {
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
    sieve();
    std::vector<int> primes;
    int lim;
    std::cin >> lim;
    for (int i = 1; i <= lim; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    int sz = (int)primes.size();
    std::vector<long long> c(sz + 1, 0);
    for (int i = 0; i < sz; i++) {
        c[i + 1] = c[i] + primes[i];
    }
    long long res = 0, range = 0;
    for (int i = 1; i <= sz; i++) {
        for (int j = i; j <= sz; j++) {
            long long sm = c[j] - c[i - 1];
            if (sm >= lim) {
                continue;
            }
            if (j - i + 1 > range && is_prime[sm]) {
                std::cout << primes[i - 1] << " " << primes[j - 1] << " = "
                          << sm << "\n";
                res = std::max(sm, res);
                range = j - i + 1;
            }
        }
    }
    std::cout << "Result: " << res << "\n";
    return 0;
}