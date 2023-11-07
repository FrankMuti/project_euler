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
    auto Eq = [=](int x, int y) -> bool {
        std::vector<int> cx(10, 0), cy(10, 0);
        while (x > 0) {
            cx[x % 10]++;
            x /= 10;
        }
        while (y > 0) {
            cy[y % 10]++;
            y /= 10;
        }
        for (int i = 0; i <= 9; i++) {
            if (cx[i] != cy[i]) {
                return false;
            }
        }
        return true;
    };
    int mn = 0;
    double mn_p = INT_MAX;
    for (int n = 10; n <= lim; n++) {
        int p = phi(n);
        if (!Eq(n, p)) {
            continue;
        }
        double res = (double)n / p;
        if (res < mn_p) {
            mn = n, mn_p = res;
            std::cout << n << " " << res << "\n";
        }
    }
    std::cout << "Min: " << mn << ", " << mn_p << " = " << phi(mn) << "\n";
    return 0;
}