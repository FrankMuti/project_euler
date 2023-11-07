#include <bits/stdc++.h>

#define int long long

struct Frac {
    int num = 0, den = 1;
    Frac() { init(0, 1); }
    Frac(int _num, int _den) { init(_num, _den); }
    void init(int _num, int _den) {
        assert(_den != 0);
        num = _num;
        den = _den;
        reduce();
    }
    void reduce() {
        int g = std::gcd(num, den);
        if (g == 1) {
            return;
        }
        num /= g;
        den /= g;
        reduce();
    }
};

Frac operator+(const Frac& lhs, const Frac& rhs) {
    int den = lhs.den * rhs.den;
    int num = ((den / lhs.den) * lhs.num) + ((den / rhs.den) * rhs.num);
    return Frac(num, den);
}

Frac operator-(const Frac& lhs, const Frac& rhs) {
    int den = lhs.den * rhs.den;
    int num = ((den / lhs.den) * lhs.num) - ((den / rhs.den) * rhs.num);
    return Frac(num, den);
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

    return Frac(num, den);
}

inline bool operator<(const Frac& lhs, const Frac& rhs) {
    double l = (double)lhs.num / (double)lhs.den;
    double r = (double)rhs.num / (double)rhs.den;
    return (l - r) < 0;
}

inline bool operator>(const Frac& lhs, const Frac& rhs) {
    double l = (double)lhs.num / (double)lhs.den;
    double r = (double)rhs.num / (double)rhs.den;
    return (l - r) > 0;
}

inline bool operator==(const Frac& lhs, const Frac& rhs) {
    return lhs.num == rhs.num && lhs.den == rhs.den;
}

inline bool operator<=(const Frac& lhs, const Frac& rhs) {
    double l = (double)lhs.num / (double)lhs.den;
    double r = (double)rhs.num / (double)rhs.den;
    return lhs == rhs || (l - r) < 0;
}

inline bool operator>=(const Frac& lhs, const Frac& rhs) {
    double l = (double)lhs.num / (double)lhs.den;
    double r = (double)rhs.num / (double)rhs.den;
    return lhs == rhs || (l - r) > 0;
}

std::ostream& operator<<(std::ostream& o, const Frac& f) {
    o << "[" << f.num << "/" << f.den << "]";
    return o;
}

double num(const Frac& f) { return double(f.num) / double(f.den); }

signed main() {
    std::set<Frac> st;
    int lim;
    std::cin >> lim;
    long long cnt = 0;
    long long end = (int)std::pow(10LL, (int)std::log10(lim * lim));
    std::cout << end << "\n";
    Frac min = Frac(3, 7) - Frac(1, lim);
    st.insert(Frac(3, 7));
    for (int i = min.num; i < min.den; i++) {
        st.insert(Frac(i, min.den));
    }
    Frac prev(0, 1);
    std::cout << std::fixed << std::setprecision(10);
    cnt = 0;
    for (auto it = st.rbegin(); it != st.rend(); it++) {
        auto f = *it;
        Frac diff = (prev / (Frac(1, -1))) + f;
        std::cout << f << " = " << diff << " = " << num(diff) << "\n";
        prev = f;
        if (++cnt > 10) {
            break;
        }
    }
    std::cout << "Count: " << st.size() << "\n";
    return 0;
}