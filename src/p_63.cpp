#include <bits/stdc++.h>

using ull = __int128;

ull pow(ull b, ull e) {
    ull res = 1;
    for (; e; b *= b, e /= 2) {
        if (e & 1) {
            res *= b;
        }
    }
    return res;
}

namespace std {
std::string to_string(ull p) {
    if (p == 0) {
        return "0";
    }
    std::string res = "";
    while (p > 0) {
        res += std::to_string((int)(p % 10));
        p /= 10;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
} // namespace std

std::ostream& operator<<(std::ostream& o, ull u) {
    o << std::to_string(u);
    return o;
}

int main() {
    ull lim = 10;
    std::unordered_set<std::string> st;
    for (ull i = 1; i <= lim; i++) {
        ull p = i;
        for (ull j = 1; j < 70; j++) {
            p = pow(i, j);
            std::string s = std::to_string(p);
            if (s.size() > 70) {
                break;
            }
            if (j == s.size()) {
                std::cout << i << " ^ " << j << " = " << s << "\n";
                st.insert(s);
            }
        }
    }
    std::cout << st.size() << "\n";
    return 0;
}