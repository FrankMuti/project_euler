from math import gcd


class Frac:
    num = 0
    den = 1

    def __init__(self, num, den, reduce=True):
        self.num = num
        assert den != 0
        self.den = den

        if reduce:
            self.reduce()

    def __add__(self, other):
        den = other.den * self.den
        num = ((den // self.den) * self.num) + ((den // other.den) * other.num)

        res = Frac(num, den)

        return res

    def __floordiv__(self, other):
        num = self.num * other.den
        den = self.den * other.num

        res = Frac(num, den)
        return res

    def __truediv__(self, other):
        return self // other

    def __str__(self):
        return "[" + str(self.num) + "/" + str(self.den) + "]"

    def reduce(self):
        g = gcd(self.num, self.den)
        if g == 1:
            return
        self.num //= g
        self.den //= g

        self.reduce()


def test():
    x = Frac(1, 2)
    y = Frac(1, 4)
    print(x, y)

    c = x + y
    print(c)
    print(x / y)


if __name__ == "__main__":
    N = 120
    a = [1] * N
    k = 1
    for i in range(1, N):
        if i % 3 == 0:
            a[i - 1] = 2 * k
            k += 1
    a[0] = 2

    def F(i, m):
        if i > m:
            return Frac(0, 1)
        if i == m:
            Frac(1, a[i])
        return Frac(1, 1) // (Frac(a[i], 1) + F(i + 1, m))

    def Sol(m):
        assert m < N
        return Frac(a[0], 1) + F(1, m)

    for i in range(100):
        frac = Sol(i)
        print("Res: ", i, "=", frac)

    num = frac.num
    _sum = 0
    while num > 0:
        _sum += num % 10
        num //= 10

    print("Sum: ", _sum)
