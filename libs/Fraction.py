from math import gcd


class Frac:
    def __init__(self, num = 0, den = 1, reduce=True):
        assert den != 0
        self.num = num
        self.den = den

        if reduce:
            self.reduce()

    def __add__(self, other):
        den = other.den * self.den
        num = ((den // self.den) * self.num) + ((den // other.den) * other.num)
        return Frac(num, den)

    def __floordiv__(self, other):
        num = self.num * other.den
        den = self.den * other.num

        return Frac(num, den)

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


