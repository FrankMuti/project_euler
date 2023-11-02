N = 101

f = [0] * N


def build():
    f[0] = 1
    for i in range(1, N):
        f[i] = f[i - 1] * i
        # print(i, f[i])


def C(n, r):
    return f[n] // (f[r] * (f[n - r]))


def main():
    cnt = 0
    for r in range(1, N):
        for n in range(r, N):
            if n == 23:
            if C(n, r) > 1000000:
                cnt += 1
    print(cnt)


if __name__ == "__main__":
    build()
    main()
