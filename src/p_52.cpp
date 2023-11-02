#include <bits/stdc++.h>

int main() {
    int lim;
    std::cin >> lim;
    auto Same = [=](const std::string& s1, int y) -> bool {
        std::string s2(std::to_string(y));
        std::sort(s2.begin(), s2.end());
        return s1 == s2;
    };
    int m = 6;
    for (int x = 1; x <= lim; x++) {
        std::string s1(std::to_string(x));
        std::sort(s1.begin(), s1.end());
        if (x % 10000 == 0) {
            std::cout << "Load: " << x << "\n";
        }
        bool ok = true;
        for (int j = 1; j <= m; j++) {
            if (!Same(s1, j * x)) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << "Got: " << x << "\n";
            exit(0);
        }
    }
    return 0;
}