#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int lim;
    std::cin >> lim; // 1E6
    auto Get = [=](int n) -> std::string {
        std::string res;
        while (n > 0) {
            res += std::to_string(n % 2);
            n /= 2;
        }
        return res;
    };
    auto IsOk = [&](const std::string& s) -> bool {
        int n = (int)s.size();
        for (int j = 0; j < n / 2; j++) {
            if (s[j] != s[n - j - 1]) {
                return false;
            }
        }
        return true;
    };
    long long sum = 0;
    for (int i = 1; i <= lim; i++) {
        std::string num = std::to_string(i);
        if (!IsOk(num)) {
            continue;
        }
        std::string s = Get(i);
        if (!IsOk(s)) {
            continue;
        }
        std::cout << i << " " << s << "\n";
        sum += i;
    }
    std::cout << "Sum: " << sum << "\n";
    return 0;
}