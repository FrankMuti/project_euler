#include <bits/stdc++.h>

#define MAX 10'000'000

constexpr long long MAX_PR = MAX;
std::bitset<MAX_PR> is_prime;

void sieve(long long lim = MAX) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (long long i = 4; i < lim; i += 2)
        is_prime[i] = 0;
    for (long long i = 3; i * i < lim; i += 2)
        if (is_prime[i]) {
            for (long long j = i * i; j < lim; j += i * 2) {
                is_prime[j] = 0;
            }
        }
}

int main() {
    sieve();
    auto Ok = [=](long long n) -> bool {
        std::vector<int> cnt(10, 0);
        int sz = 0;
        while (n > 0) {
            cnt[n % 10]++;
            n /= 10;
            sz++;
        }
        int res = 1;
        for (int i = 1; i <= sz; i++) {
            res &= cnt[i] == 1;
        }
        return res && cnt[0] == 0;
    };
    std::cout << "Done Sieve \n";
    int lim = MAX;
    // std::cin >> lim;
    for (int i = 1; i <= lim; i++) {
        if (!is_prime[i] || !Ok(i)) {
            continue;
        }
        std::cout << i << "\n";
    }
    return 0;
}