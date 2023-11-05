def m_pow(b, e):
    res = 1
    while e > 0:
        if e % 2 == 1:
            res *= b
        b *= b
        e //= 2
    return res


if __name__ == "__main__":
    lim = int(input())
    st = set()
    for i in range(1, lim + 1):
        for j in range(1, 64):
            p = str(i**j)
            if len(p) > 64:
                break
            if len(p) == j:
                print(i, "^", j, "=", p)
                st.add(p)
    print(len(st))
