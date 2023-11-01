#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int _min = 2, _max = 1000;
    auto Len = [=](int x, int y) -> int {
        std::map<int, int> mp;
        std::string res = "";
        int rem = x % y;
        while (rem != 0 && mp.find(rem) == mp.end()) {
            mp[rem] = res.size();
            rem *= 10;
            res += std::to_string(rem / y);
            rem %= y;
        }
        return rem == 0 ? -1 : res.size() - mp[rem];
    };
    int ans = 0, l_ans = 0;
    for (int i = _min; i <= _max; i++) {
        int len = Len(1, i);
        if (len != -1 && len > l_ans) {
            l_ans = len;
            ans = i;
        }
    }
    std::cout << ans << " => " << l_ans << "\n";
    return 0;
}