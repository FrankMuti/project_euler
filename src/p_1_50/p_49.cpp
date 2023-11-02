#include <bits/stdc++.h>

constexpr int MAX_PR = 50000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = 20000) {
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
    auto Str = [=](int n) -> std::string {
        std::string s(std::to_string(n));
        std::sort(s.begin(), s.end());
        return s;
    };
    auto Valid = [&](int x, int y, int z) -> bool {
        if (!(is_prime[x] && is_prime[y] && is_prime[z])) {
            return false;
        }
        return Str(x) == Str(y) && Str(y) == Str(z);
    };
    int l = 1000, r = 9999;
    for (int i = l; i <= r; i++) {
        for (int d = 1; i + 2 * d <= r; d++) {
            int x1 = i, x2 = i + d, x3 = i + 2 * d;
            if (Valid(x1, x2, x3)) {
                std::cout << x1 << " " << x2 << " " << x3 << "\n";
            }
        }
    }
    return 0;
}