#include <bits/stdc++.h>

constexpr int inf = 987654321;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto Ok = [=](const std::string& s) -> bool {
        std::vector<int> cnt(10, 0);
        for (auto c : s) {
            cnt[c - '0']++;
        }
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] != 1) {
                return false;
            }
        }
        return true && !cnt[0];
    };
    int lim;
    std::cin >> lim;
    long long res = 0;
    for (long long i = 2; i <= lim; i++) {
        int n = 1;
        std::string sm = "";
        bool ok = false;
        while (sm.size() <= 9) {
            sm += std::to_string(i * n++);
            if (sm.size() == 9 && Ok(sm)) {
                res = std::max(res, std::stoll(sm));
                std::cout << i << ", " << n << " = " << sm << "\n";
            }
        }
    }
    std::cout << "Res: " << res << "\n";
    return 0;
}