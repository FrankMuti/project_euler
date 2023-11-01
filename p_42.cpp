#include <bits/stdc++.h>

void solve() {}

int main() {
    std::map<int, int> mp;
    for (int n = 1; n <= 100; n++) {
        mp[(n * (n + 1)) / 2] = 1;
    }
    std::ifstream is("words.txt");
    std::string s, token, delimiter = ",";
    is >> s;
    int pos = 0;
    int cnt = 0;
    auto Calc = [=](const std::string& x) -> int {
        int sm = 0;
        for (auto c : x) {
            if (c >= 'A' && c <= 'Z') {
                sm += (c - 'A') + 1;
            }
        }
        return sm;
    };
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        std::cout << token << " ";
        if (mp[Calc(token)]) {
            std::cout << Calc(token);
            ++cnt;
        }
        std::cout << "\n";
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << " ";
    if (mp[Calc(s)]) {
        std::cout << Calc(s);
        ++cnt;
    }
    std::cout << "\n";
    std::cout << "Count: " << cnt << "\n";
    return 0;
}