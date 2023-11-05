#include <bits/stdc++.h>

#define N 124
#define INF 1E9

int main() {
    std::vector a(N + 1, std::vector<int>(N + 1, -INF));
    std::ifstream in("67_triangle.txt");
    std::string line;
    int i = 1, j = 1;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        int val;
        while (ss >> val) {
            a[i][j++] = val;
        }
        j = 1;
        i++;
    }
    int n = i - 1;
    std::vector dp(N + 1, std::vector<long long>(N + 1, -INF));
    dp[0][0] = 0;
    long long res = -INF;
    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            dp[y][x] = std::max(dp[y - 1][x - 1], dp[y - 1][x]) + a[y][x];
            res = std::max(res, dp[y][x]);
        }
    }
    std::cout << "Sum: " << res << "\n";
    return 0;
}