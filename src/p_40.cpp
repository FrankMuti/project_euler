#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s = "0";
    for (int i = 1;; i++) {
        s += std::to_string(i);
        if (s.size() > 1000000) {
            break;
        }
        if (i % 50000 == 0) {
            std::cout << "Here: " << i << "\n";
        }
    }
    int res = 1;
    for (int p = 1; p <= 1000000; p *= 10) {
        std::cout << p << " " << s[p] << "\n";
        res *= (s[p] - '0');
    }
    std::cout << "Res: " << res << "\n";
    return 0;
}