#include <bits/stdc++.h>

constexpr int MAX_PR = 5000000;
std::bitset<MAX_PR> is_prime;

void sieve(int lim = 2000000) {
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
}

int main() {
    sieve();
    std::map<std::string, int> mp;
    int lim;
    std::cin >> lim;
    for (int i = 1; i <= 2 * lim; i++) {
        if (is_prime[i]) {
            mp[std::to_string(i)] = 1;
        }
    }
    std::string max = "";
    int max_len = 0;
    for (int i = 100000; i <= lim; i++) {
        if (!is_prime[i]) {
            continue;
        }
        std::string s = std::to_string(i);
        std::cout << "Checking: " << i << "\n";
        int sz = (int)s.size();
        int max_in = 0;
        std::string max_in_s = "";
        for (int msk = 1; msk < 1 << sz; msk++) {
            int mask = msk;
            std::vector<int> m(sz, 0);
            for (int j = 0; mask > 0; j++, mask /= 2) {
                if (mask & 1) {
                    m[j] = 1;
                }
            }
            int cnt = 0;
            std::string min = "";
            for (int j = 0; j < 10; j++) {
                std::string t = s;
                for (int k = 0; k < sz; k++) {
                    if (m[k]) {
                        t[k] = char('0') + j;
                    }
                }
                if (std::stoll(t) < i) {
                    continue;
                }
                if (min == "" && mp[t]) {
                    min = t;
                }
                cnt += mp[t];
            }
            if (cnt > max_in) {
                max_in = cnt;
                max_in_s = min;
            }
            if (min != "" && cnt > max_len) {
                max = min;
                max_len = cnt;
            }
        }
        std::cout << max_in_s << " == " << max_in << "\n";
        if (max_in == 8) {
            std::cout << "Res: " << max << ", " << max_len << "\n";
            exit(0);
        }
    }
    std::cout << "Res: " << max << ", " << max_len << "\n";
    return 0;
}