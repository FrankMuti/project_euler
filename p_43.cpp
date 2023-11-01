#include <bits/stdc++.h>

int main() {
    std::string a = "1406357289"; //"0123456789";
    int op = 0;
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17};
    int n = (int)a.size();
    long long sum = 0;
    do {
        if (++op % 100000 == 0) {
            std::cout << op << "\n";
        }
        bool ok = true;
        for (int i = 1; i < n - 2; i++) {
            int n = std::stoll(a.substr(i, 3));
            if (n % primes[i - 1] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << a << "\n";
            sum += std::stoll(a);
        }
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << "Sum: " << sum << "\n";
    return 0;
}