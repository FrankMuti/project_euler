#include <bits/stdc++.h>

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    auto Ok = [=](int i, int j, int k, int per) -> bool {
        return (i * i) + (j * j) == (k * k) && (i + j + k == per);
    };
    int lim;
    std::cin >> lim;
    int res = 0, res_cnt = 0;
    long long ops = 0;
    for (int p = 3; p <= lim; p++) {
        int cnt = 0;
        for (int i = 1; i <= p; i++) {
            for (int j = i; j <= p; j++) {
                for (int k = j; k <= p; k++) {
                    ops++;
                    if (Ok(i, j, k, p)) {
                        // std::cout << i << " " << j << " " << k << "\n";
                        cnt++;
                    }
                }
            }
        }
        if (cnt > 0) {
            std::cout << p << " " << cnt << "\n";
        }
        if (cnt > res_cnt) {
            res_cnt = cnt;
            res = p;
        }
    }
    std::cout << "Res: " << res << ", " << res_cnt << "\n";
    std::cout << "Operatios: " << ops << "\n";
    return 0;
}