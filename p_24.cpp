#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    assert(n > 0 && n <= 10);
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 0);
    int cnt = 0;
    do {
        if (++cnt % 10000 == 0) {
            std::cout << cnt << ": ";
            for (int i = 0; i < n; i++) {
                std::cout << a[i] << " \n"[i + 1 == n];
            }
        }
    } while (std::next_permutation(a.begin(), a.end()));
    return 0;
}