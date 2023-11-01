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
    sieve();
    int lim;
    std::cin >> lim;
    std::vector<int> primes;
    for (int i = 2; i <= lim; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    auto IsSquare = [=](int n) -> bool {
        double g = std::sqrt(n);
        int r1 = std::floor(g), r2 = std::ceil(g);
        return (r1 * r1 == n) || (r2 * r2 == n);
    };
    int sz = (int)primes.size();
    for (int i = 9; i <= lim; i += 2) {
        if (is_prime[i]) {
            continue;
        }
        bool ok = false;
        int n = i, j = 0;
        while (j < sz) {
            if (n - primes[j] < 0)
                break;
            if ((n - primes[j]) % 2 != 0) {
                j++;
                continue;
            }
            // j++;
            int diff = (n - primes[j]) / 2;
            if (IsSquare(diff)) {
                // std::cout << i << " = " << primes[j] << " + 2 * "
                // << (int)std::sqrt(diff) << " ^ 2\n";
                ok = true;
                break;
            }
            j++;
        }
        if (!ok) {
            std::cout << "Not: " << i << "\n";
        }
    }
    return 0;
}