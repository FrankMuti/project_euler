from decimal import Decimal, getcontext

getcontext().prec = 50


def calc(num, den):
    mp = {}
    rem = num % den
    res = ""
    while (rem != 0) and (rem not in mp.keys()):
        mp[rem] = len(res)
        rem *= 10
        res += str(rem // den)
        rem %= den

    return "-" if rem == 0 else res[mp[rem]:]


_min = 2
_max = 10

ans, l_ans = 0, 0

for i in range(_min, _max + 1):
    res = calc(1, i)
    if res != "-":
        print(i, res, len(res))
        if len(res) > l_ans:
            l_ans = len(res)
            ans = i

print("=======")
print(ans, l_ans)

print(1 / Decimal(183))