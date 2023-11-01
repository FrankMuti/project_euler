#include <bits/stdc++.h>

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    std::string s = "123456789";
    int freq = 0, n = 9, cnt = 0;
    std::unordered_set<long long> st;
    long long sum = 0;
    do {
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int l1 = i, l2 = j - i + 1, l3 = n - j + 1;
                std::string sa = s.substr(0, i);
                std::string sb = s.substr(i, j - i + 1);
                std::string sc = s.substr(j + 1);
                if (sa.size() == 0 || sb.size() == 0 || sc.size() == 0) {
                    continue;
                }
                long long a = std::stoll(sa), b = std::stoll(sb),
                          c = std::stoll(sc);
                if (a * b == c && st.count(c) == 0) {
                    std::cout << a << " * " << b << " = " << c << "\n";
                    st.insert(c);
                    sum += c;
                }
            }
        }
    } while (std::next_permutation(s.begin(), s.end()));
    std::cout << sum << "\n";
    return 0;
}