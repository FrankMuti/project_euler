#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int lim;
    std::cin >> lim;
    std::vector<long long> t(lim + 1), p(lim + 1), h(lim + 1);
    for (long long n = 1; n <= lim; n++) {
        t[n] = n * (n + 1) / 2;
        p[n] = n * (n * 3 - 1) / 2;
        h[n] = n * (n * 2 - 1);
    }
    for (int n = 1; n <= lim; n++) {
        auto b1 = std::binary_search(p.begin(), p.end(), t[n]);
        auto b2 = std::binary_search(h.begin(), h.end(), t[n]);
        if (b1 && b2) {
            std::cout << n << " " << t[n] << "\n";
        }
    }
    return 0;
}