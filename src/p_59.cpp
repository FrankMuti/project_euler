#include <bits/stdc++.h>

std::vector<char> read(std::string s) {
    std::vector<char> res;
    std::string delimiter = ",";
    auto ToChar = [&](std::string token) -> void {
        int val = (int)std::stoll(token);
        char c = char(val);
        res.push_back(c);
    };

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        ToChar(token);
        s.erase(0, pos + delimiter.length());
    }
    ToChar(s);
    return res;
}

bool test(std::string word, std::string key) {
    int alphas = 0, sz = word.size();
    for (int i = 0; i < (int)word.size(); i++) {
        word[i] ^= key[i % 3];
        if (std::isalpha(word[i]) || word[i] == ' ') {
            alphas++;
        }
    }
    if (alphas > 1300) {
        int sum = 0;
        for (char c : word) {
            sum += int(c);
        }
        std::cout << "===================================\n";
        std::cout << "KEY: " << key << ", SUM: " << sum << "\n";
        std::cout << "===================================\n";
        std::cout << word << "\n";
        std::cout << "===================================\n";
        return true;
    }
    return false;
}

int main() {
    std::string words;
    std::ifstream in("59_cipher.txt");
    if (in.fail()) {
        exit(1);
    }
    std::getline(in, words);
    auto vals = read(words);
    std::string s;
    for (auto c : vals) {
        s += c;
    }
    int cnt = 0, ok = 0;
    std::string key = "";
    for (char x = 'a'; !ok && x <= 'z'; x++) {
        for (char y = 'a'; !ok && y <= 'z'; y++) {
            for (char z = 'a'; !ok && z <= 'z'; z++) {
                key = "";
                key = ((key + x) + y) + z;
                ok = test(s, key);
            }
        }
    }
    return 0;
}
