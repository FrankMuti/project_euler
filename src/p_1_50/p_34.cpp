#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 10;
    std::vector<long long> f(n, 0);
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        f[i] = i * 1LL * f[i - 1];
    }
    int lim;
    std::cin >> lim;
    long long sum = 0;
    for (long long i = 3; i < lim; i++) {
        long long n = i, sm = 0;
        while (n > 0) {
            sm += f[n % 10];
            n /= 10;
        }
        if (sm == i) {
            std::cout << sm << "\n";
            sum += sm;
        }
    }
    std::cout << "Sum: " << sum << "\n";
    return 0;
}