#include <bits/stdc++.h>

int count(int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            res += i;
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int lim; // 28123
    std::cin >> lim;
    std::vector<int> nums;
    for (int i = 1; i <= lim; i++) {
        int sm = count(i);
        if (sm > i) {
            nums.push_back(i);
        }
    }
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    std::vector<int> res(lim * 2, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i] + nums[j] > lim) {
                break;
            }
            res[nums[i] + nums[j]] = 0;
        }
    }
    long long sm = 0;
    for (int i = 1; i <= lim; i++) {
        if (res[i]) {
            sm += i;
        }
    }
    std::cout << sm << "\n";
    return 0;
}