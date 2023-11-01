#include <bits/stdc++.h>

struct Frac {
    int num, den;
};

inline bool operator==(const Frac& lhs, const Frac& rhs) {
    return lhs.num == rhs.num && lhs.den == rhs.den;
}

std::ostream& operator<<(std::ostream& o, const Frac& obj) {
    o << "{" << obj.num << "/" << obj.den << "} ";
    return o;
}

std::multiset<int> fac(int n) {
    std::multiset<int> res;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            res.insert(x);
            n /= x;
        }
    }
    if (n > 1) {
        res.insert(n);
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int mn = 10, mx = 99;
    long long r_num = 1, r_den = 1;
    auto Low = [](Frac x) -> Frac {
        auto fn = fac(x.num);
        auto fd = fac(x.den);
        std::vector<int> v(fn.size() + fd.size() + 10, -1);
        std::set_intersection(fn.begin(), fn.end(), fd.begin(), fd.end(),
                              v.begin());
        int lx = x.num, ly = x.den;
        for (auto vi : v) {
            if (vi == -1) {
                continue;
            }
            std::multiset<int>::iterator i1, i2;
            if ((i1 = fn.find(vi)) != fn.end()) {
                fn.erase(i1);
                lx /= vi;
            }
            if ((i2 = fd.find(vi)) != fn.end()) {
                fd.erase(i2);
                ly /= vi;
            }
        }
        return {lx, ly};
    };
    for (int x = mn; x < mx; x++) {
        for (int y = x + 1; y <= mx; y++) {
            std::string num = std::to_string(x), den = std::to_string(y);
            Frac b = Low({x, y});
            int ok = 0, sz = 2;
            Frac a1{0, 0};
            if (num[0] == den[1])
                a1 = {num[1] - '0', den[0] - '0'};
            if (num[1] == den[0])
                a1 = {num[0] - '0', den[1] - '0'};
            if (Low(a1) == b) {
                ok = 1;
            }
            if (ok) {
                std::cout << Frac{x, y} << " => " << b << " | " << a1 << "\n";
                r_num *= b.num, r_den *= b.den;
            }
        }
    }
    auto res = Frac{r_num, r_den};
    std::cout << res << " => " << Low(res) << "\n";
    return 0;
}