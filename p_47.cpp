#include <bits/stdc++.h>

int main() {
    int lim; // 1000000
    std::cin >> lim;
    int cnt = 4;
    std::vector<int> prev;
    for (int a = 2; a <= lim; a++) {
        std::unordered_set<int> st;
        int n = a;
        for (int x = 2; x * x <= n; x++) {
            while (n % x == 0) {
                st.insert(x);
                n /= x;
            }
        }
        if (n > 1) {
            st.insert(n);
        }
        if (st.size() == cnt) {
            if (prev.size() == 0) {
                prev.push_back(a);
            } else if ((prev.back()) + 1 == a) {
                prev.push_back(a);
            } else {
                prev.clear();
                prev.push_back(a);
            }
        }
        if (prev.size() >= cnt) {
            for (auto it : prev) {
                std::cout << it << "\n";
            }
            exit(0);
        }
    }
    return 0;
}