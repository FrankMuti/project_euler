#include <bits/stdc++.h>

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    int lim;
    std::cin >> lim;
    int mx = 0;
    double mx_p = 0;
    for (int n = 1; n <= lim; n++) {
        double res = (double)n / phi(n);
        if (res > mx_p) {
            mx = n;
            mx_p = res;

            std::cout << n << " " << res << "\n";
        }
    }
    std::cout << "Max: " << mx << ", " << mx_p << "\n";
    return 0;
}