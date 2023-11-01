#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    assert(n % 2 == 1); // odd
    std::vector a(n, std::vector<int>(n, 0));
    std::vector<int> diri{0, 1, 0, -1};
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
    int i = n / 2, j = n / 2;
    int dir = -1, cnt = 1;
    a[i][j] = cnt;
    int sum = cnt;
    while (ValidCord(i, j) && cnt <= (n * n)) {
        int next_dir = (dir + 1) % 4;
        if (Valid(i + diri[next_dir], j + dirj[next_dir])) {
            dir = next_dir;
        }
        i += diri[dir], j += dirj[dir];
        a[i][j] = ++cnt;
        if (diag.count({i, j})) {
            sum += cnt;
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
    std::cout << sum << "\n";
    return 0;
}