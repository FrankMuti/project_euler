from math import gcd
import sys

sys.setrecursionlimit(15000)
print("Limit: ", sys.getrecursionlimit())


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


if __name__ == "__main__":
    lim = int(input())
    lim = min(lim, 10001)
    N = lim

    def F(i, m):
        if i > m:
            return Frac(0, 1)
        if i == m:
            Frac(1, 2)
        return Frac(1, 1) // (Frac(2, 1) + F(i + 1, m))

    def Sol(m):
        assert m < N
        return Frac(1, 1) + F(1, m)

    count = 0

    for i in range(lim):
        res = Sol(i)
        num = res.num
        den = res.den

        if len(str(num)) > len(str(den)):
            print("Iter: ", i)
            count += 1
    print("Count: ", count)
