#include <bits/stdc++.h>

constexpr long long max = 100000;

int main() {
    std::cout << "Prep...\n";
    std::vector<long long> f(max + 1, 0);
    std::unordered_map<long long, int> mp;
    for (long long n = 1; n <= max; n++) {
        f[n] = n * (n * 3 - 1) / 2;
        mp[f[n]] = 1;
    }
    std::cout << "Lim: ";
    long long lim;
    std::cin >> lim; // 10000
    long long res = LLONG_MAX;
    for (int i = 1; i <= lim; i++) {
        for (int j = i + 1; j <= lim; j++) {
            long long sm = f[i] + f[j];
            long long df = std::abs(f[i] - f[j]);
            if (mp[sm] && mp[df]) {
                std::cout << "Found: " << i << " " << j << "; p " << f[i] << " "
                          << f[j] << "\n";
                res = std::min(res, df);
            }
        }
    }
    std::cout << "Res: " << res << "\n";
    return 0;
}