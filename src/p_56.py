def sum_digits(n):
    res = 0
    while n > 0:
        res += n % 10
        n //= 10
    return res


if __name__ == "__main__":
    lim = int(input())
    lim = min(lim, 100)
    mx, mx_sum = 0, 0
    m_a, m_b = 0, 0
    for a in range(1, lim):
        for b in range(1, lim):
            n = a**b
            sm = sum_digits(n)
            print(f"{a:2d}^{b:2d} = {sm:3d}; {n}")
            if sm > mx_sum:
                mx_sum = sm
                m_a = a
                m_b = b
                mx = n
    print("Max: ", f"{m_a:2d} ^ {m_b:2d} = {mx_sum:3d}; {mx}")
    print("Sum: ", mx_sum)
