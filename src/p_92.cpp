#include <bits/stdc++.h>

int main() {
    int lim;
    std::cin >> lim;
    auto Next = [=](int n) -> int {
        int sm = 0;
        while (n > 0) {
            int v = n % 10;
            sm += (v * v);
            n /= 10;
        }
        return sm;
    };
    int cnt = 0;
    for (int i = 2; i <= lim; i++) {
        int nx = i;
        while ((nx = Next(nx))) {
            if (nx == 1 || nx == 89) {
                break;
            }
        }
        if (i % 10000 == 0) {
            std::cout << "No: " << i << "\n";
        }
        if (nx == 89) {
            // std::cout << "Here: " << i << "\n";
            ++cnt;
        }
    }
    std::cout << "count: " << cnt << "\n";
    return 0;
}