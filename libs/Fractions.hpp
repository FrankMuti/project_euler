#include <bits/stdc++.h>

template<typename T = int>
struct Frac {
    T num = 0, den = 1;
    Frac() {
        init(0, 1);
    }
    Frac(T _num, T _den) {
        init(_num, _den);
    }
    void init(T _num, T _den) {
        assert(_den != 0);
        num = _num;
        den = _den;

        reduce();
    }
    void reduce() {
        T g = std::gcd(num, den);
        if (g == 1) {
            return;
        }
        num /= g;
        den /= g;
        reduce();
    }
    Frac& operator+=(const Frac& other) {
        *this = *this + other;        
        return *this;
    }
    Frac& operator-=(const Frac& other) {
        *this = *this / other;
        return *this;
    }
};

template<typename T>
Frac<T> operator+(const Frac<T>& lhs, const Frac<T>& rhs) {
    T den = lhs.den * rhs.den;
    T num = ((den / lhs.den) * lhs.num) + ((den / rhs.den) * (rhs.num));
    return Frac(num, den);
}

template<typename T>
Frac<T> operator-(const Frac<T>& lhs, const Frac<T>& rhs) {
    T den = lhs.den * rhs.den;
    T num = ((den / lhs.den) * lhs.num) - ((den / rhs.den) * (rhs.num));
    return Frac(num, den);
}

template<typename T>
Frac<T> operator/(const Frac<T>& lhs, const Frac<T>& rhs) {
    T num = lhs.num * rhs.den;
    T den = lhs.den * rhs.num;
    return Frac(num, den);
}

template<typename T>
Frac<T> operator*(const Frac<T>& lhs, const Frac<T>& rhs) {
    T num = lhs.num * rhs.num;
    T den = lhs.den * rhs.den;
    return Frac(num, den);
}

template<typename T>
bool operator==(const Frac<T>& lhs, const Frac<T>& rhs) {
    Frac l(lhs.num, lhs.den);
    Frac r(rhs.num, rhs.den);
    return l.num == r.num && l.den == r.den;
}

template<typename T>
bool operator<(const Frac<T>& lhs, const Frac<T>& rhs) {
    long double l = static_cast<long double>(lhs.num) / lhs.den;
    long double r = static_cast<long double>(rhs.num) / rhs.den;
    return l < r;
}

template<typename T>
bool operator>(const Frac<T>& lhs, const Frac<T>& rhs) {
    long double l = static_cast<long double>(lhs.num) / lhs.den;
    long double r = static_cast<long double>(rhs.num) / rhs.den;
    return l > r;
}

template<typename T>
std::ostream& operator<<(std::ostream& o, const Frac<T>& f) {
    return o << "[" << f.num << "/" << f.den << "]";
}

int main() {
    Frac x(1, 4);
    Frac y(1, 2);
    std::cout << x + y << "\n";
    std::cout << x - y << "\n";
    std::cout << x / y << "\n";
    std::cout << x * y << "\n";
    std::cout << (x > y ? "False") << "\n";
    std::cout << (x < y ? "True") << "\n";
    return 0;
}

