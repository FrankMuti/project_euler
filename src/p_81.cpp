#include <bits/stdc++.h>

#define N 1024
#define INF 1E9

#define DEBUG 1

int main(int argc, char** argv) {
    std::vector a(N + 1, std::vector<int>(N + 1, INF));
    std::string def_file = "81_matrix_test.txt";
    if (argc > 1) {
        def_file = argv[1];
    }
    std::ifstream in(def_file);
    if (in.fail()) {
        std::cerr << "Error: Failed to open file'" << def_file << "'\n";
        exit(1);
    }
    std::string line;
    int n = 1, m = 0;
    while (std::getline(in, line)) {
        int curr = 0, j = 1;
        for (auto c : line) {
            if (c >= '0' && c <= '9') {
                curr *= 10;
                curr += (c - '0');
            } else {
                a[n][j++] = curr;
                curr = 0;
            }
        }
        // a[n][j] = curr;
        n++;
    }
    --n;
    std::vector dp(N + 1, std::vector<long long>(N + 1, INF));
    dp[0][0] = dp[1][0] = dp[0][1] = 0;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            dp[y][x] = std::min(dp[y - 1][x], dp[y][x - 1]) + a[y][x];
        }
    }
#ifdef DEBUG
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            std::cout << a[y][x] << " \n"[x == n];
        }
    }
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            std::cout << std::setw(11) << dp[i][j] << " \n"[j == n + 1];
        }
    }
#endif
    std::cout << "Min: " << dp[n][n] << "\n";
    return 0;
}