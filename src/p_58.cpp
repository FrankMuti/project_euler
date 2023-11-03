#include <bits/stdc++.h>

// WARNING: MEMORY ~3.5GB

constexpr int MAX_PR = 900000000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = MAX_PR) {
    std::cout << "preparing sieve...";
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 4; i < lim; i += 2)
        is_prime[i] = 0;
    for (int i = 3; i * i < lim; i += 2)
        if (is_prime[i]) {
            for (int j = i * i; j < lim; j += i * 2) {
                is_prime[j] = 0;
            }
        }
    std::cout << "done.\n";
}

void solve(int n) {
    if (n % 2 == 0) {
        ++n;
    }
    assert(n > 0 && n % 2 == 1); // odd
    std::vector a(n, std::vector<int>(n, 0));
    std::vector<int> diri{0, -1, 0, 1};
    std::vector<int> dirj{1, 0, -1, 0};
    std::set<std::pair<int, int>> diag;
    for (int i = 0; i < n; i++) {
        diag.insert({i, i});
    }
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        diag.insert({i, j});
    }
    auto ValidCord = [=](int i, int j) -> bool {
        return 0 <= i && i < n && 0 <= j && j < n;
    };
    auto Valid = [&](int i, int j) -> bool {
        return ValidCord(i, j) && a[i][j] == 0;
    };
    int box = 3;
    int i = n / 2, j = n / 2;
    int dir = -1, cnt = 1;
    a[i][j] = cnt;
    int sum = 0, dgs = 1;
    while (ValidCord(i, j) && cnt <= (n * n)) {
        int next_dir = (dir + 1) % 4;
        if (Valid(i + diri[next_dir], j + dirj[next_dir])) {
            dir = next_dir;
        }
        i += diri[dir], j += dirj[dir];
        a[i][j] = ++cnt;
        assert(cnt < MAX_PR);
        if (diag.count({i, j})) {
            sum += is_prime[cnt];
            dgs++;
        }
        if (cnt >= (box * box)) {
            std::cout << "Size " << box << ": ";
            std::cout << sum << "/" << dgs << " = ";
            double x = (double)sum, y = (double)dgs;
            std::cout << std::setprecision(10) << std::fixed;
            std::cout << x / y << "\n";
            if ((x / y) < 0.1) {
                std::cout << "Here: " << box << "\n";
                exit(0);
            }
            box += 2;
        }
    }
    int wid = 2;
    auto Print = [=](const std::vector<std::vector<int>>& v) -> void {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << std::setw(wid) << v[i][j] << " \n"[j + 1 == n];
            }
        }
    };
    // Print(a);
}

int main() {
    sieve();
    solve(int(std::sqrt(MAX_PR) - 5));
    return 0;
}