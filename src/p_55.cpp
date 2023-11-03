#include <bits/stdc++.h>

using i128 = __int128;

std::istream& operator>>(std::istream& is, i128& n) {
    n = 0;
    std::string s;
    is >> s;

    for (auto c : s) {
        n = 10 * n + c - '0';
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

namespace std {
std::string to_string(i128 n) {
    if (n == 0) {
        return "0";
    }
    std::string s;
    while (n > 0) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

i128 stoi128(std::string s) {
    i128 n = 0;
    for (auto c : s) {
        n = 10 * n + c - '0';
    }
    return n;
}
}; // namespace std

#define int i128

signed main() {
    auto IsPalindrome = [&](int n) -> bool {
        std::string s(std::to_string(n));
        int sz = (int)s.size();
        for (int i = 0, j = sz - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    };
    auto Rev = [=](int n) -> int {
        std::string s(std::to_string(n));
        std::reverse(s.begin(), s.end());
        if (n < 0) {
            std::cout << n << "!Overflow\n";
            exit(0);
        }
        return stoi128(s);
    };
    int lim;
    std::cin >> lim;
    int count = 0;
    for (int n = 1; n <= lim; n++) {
        int val = n, is_p = 0;
        for (int i = 0; i < 50 && !is_p; i++) {
            int x = val, y = Rev(val);
            val = x + y;
            if (IsPalindrome(val)) {
                is_p = 1;
                break;
            }
        }
        if (is_p == 0) {
            std::cout << n << " Lychrel\n";
            ++count;
        }
    }
    std::cout << "Count: " << count << "\n";
    return 0;
}
