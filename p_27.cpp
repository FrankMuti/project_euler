#include <bits/stdc++.h>

constexpr int MAX_PR = 5000000, LIM = 3000000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = LIM) {
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
    auto F = [=](int n, int a, int b) -> int {
        return std::abs((n * n) + (n * a) + (b));
    };
    struct Res {
        int n, a, b;
    };
    int lim;
    std::cin >> lim;
    Res res{0, 0, 0};
    int res_c = 0;
    for (int a = -lim; a <= lim; a++) {
        for (int b = -lim; b <= lim; b++) {
            int n = 0;
            while (true) {
                int val;
                if ((val = F(n, a, b)) > LIM) {
                    std::cout << F(n, a, b) << " | " << n << " " << a << " "
                              << b << "\n";
                    exit(0);
                }
                if (!is_prime[val]) {
                    break;
                }
                n++;
            }
            if (n > res_c) {
                res = {n, a, b};
                res_c = n;
            }
        }
    }
    std::cout << "===============\n";
    std::cout << res.n << "^2 + " << res.n << "*" << res.a << " + " << res.b
              << "\n";
    std::cout << res.a * res.b << "\n";
    std::cout << "count: ";
    std::cout << res_c << "\n";
    return 0;
}