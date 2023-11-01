#include <bits/stdc++.h>

std::vector<int> factors(int n) {
    std::vector<int> res;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            res.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
}

std::vector<int> combine(std::vector<int> v1, int n) {
    int sz = (int)v1.size();
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < n - 1; j++) {
            v1.push_back(v1[i]);
        }
    }
    std::sort(v1.begin(), v1.end());
    return v1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int lim;
    std::cin >> lim;
    assert(lim > 2);
    std::set<std::vector<int>> st;
    for (int a = 2; a <= lim; a++) {
        for (int b = 2; b <= lim; b++) {
            std::vector<int> v = combine(factors(a), b);
            // // std::cout << a << " ^ " << b << " = " << std::pow(a, b) << "
            // {"; for (auto it : v) { std::cout << it << " ";
            // }
            // std::cout << "}  = ";
            // std::cout << st.count(v) << "\n";
            st.insert(v);
        }
    }
    std::cout << st.size() << "\n";
    return 0;
}