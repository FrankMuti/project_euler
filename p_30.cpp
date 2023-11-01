#include <bits/stdc++.h>

int pow(int b, int e) {
    int res = 1;
    for (; e; b *= b, e /= 2) {
        if (e & 1) {
            res *= b;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int base = 5;
    std::vector<int> pwr(10, 0);
    int lim;
    std::cin >> lim;
    for (int i = 1; i <= 9; i++) {
        pwr[i] = pow(i, base);
    }
    int sum = 0;
    for (int i = 2; i <= lim; i++) {
        int sm = 0, n = i;
        while (n > 0) {
            sm += pwr[n % 10];
            n /= 10;
        }
        if (sm == i) {
            std::cout << i << "\n";
            sum += i;
        }
    }
    std::cout << "Sum: " << sum << "\n";
    return 0;
}