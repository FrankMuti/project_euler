#include <bits/stdc++.h>

// !! OVERFLOWS. USE LANGUAGE WITH BIG INTEGER

struct Frac {
    int num = 0, den = 1;
};

std::ostream& operator<<(std::ostream& o, const Frac& f) {
    o << "[" << f.num << "/" << f.den << "]";
    return o;
}

Frac reduce(Frac h) {
    int num = h.num, den = h.den;
    int g = std::gcd(num, den);

    if (g == 1) {
        return {num, den};
    }

    num /= g;
    den /= g;
    return reduce({num, den});
}

Frac operator+(const Frac& lhs, const Frac& rhs) {
    int den = lhs.den * rhs.den;
    int num = ((den / lhs.den) * lhs.num) + ((den / rhs.den) * rhs.num);

    return reduce({num, den});
}

Frac operator+=(Frac& lhs, const Frac& rhs) {
    Frac tmp = lhs + rhs;
    lhs.num = tmp.num;
    lhs.den = tmp.den;
    return tmp;
}

Frac operator/(const Frac& lhs, const Frac& rhs) {
    int num = lhs.num * rhs.den;
    int den = lhs.den * rhs.num;

    return reduce({num, den});
}

Frac testFun2(int n) {
    if (n == 1) {
        return Frac{1, 2};
    }
    return Frac{1, 1} / (Frac{2, 1} + testFun2(n - 1));
}

Frac testFun(int n) { return Frac{1, 1} + testFun2(n); }

void test() {
    std::cout << testFun(1) << "\n";
    std::cout << testFun(2) << "\n";
    std::cout << testFun(3) << "\n";
    std::cout << testFun(4) << "\n";
    exit(0);
}

signed main() {
    int n = 101;
    std::vector<int> a(n + 1, 1);
    for (int i = 1, k = 1; i <= n; i++) {
        if (i % 3 == 0) {
            a[i - 1] = 2 * k++;
        }
    }
    a[0] = 2;
    std::function<Frac(int, int)> F = [&](int i, int m) -> Frac {
        // std::cout << "Loop: " << i << "/" << m << "\n";
        if (i >= m) {
            return Frac{1, a[i]};
        }
        return Frac{1, 1} / (Frac{a[i], 1} + F(i + 1, m));
    };
    std::function<Frac(int)> Solve = [&](int m) -> Frac {
        if (m == 0) {
            return Frac{a[0], 1};
        }
        return Frac{a[0], 1} + F(1, m);
    };
    for (int i = 0; i <= 10; i++) {
        std::cout << "Test " << i << ": " << Solve(i) << "\n";
    }
    int lim;
    std::cin >> lim;
    std::cout << lim << ": " << Solve(lim) << "\n";
    return 0;
}
