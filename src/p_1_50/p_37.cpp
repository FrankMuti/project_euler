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
    int lim, sum = 0;
    std::cin >> lim;
    for (int i = 10; i <= lim; i++) {
        if (!is_prime[i]) {
            continue;
        }
        std::string s = std::to_string(i);
        bool ok = true;
        int n = (int)s.size();
        for (int i = 0; i < n; i++) {
            int n1 = std::stoll(s.substr(0, n - i));
            int n2 = std::stoll(s.substr(i));
            if (!(is_prime[n1] && is_prime[n2])) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << i << "\n";
            sum += i;
        }
    }
    std::cout << "Count: " << sum << "\n";
    return 0;
}