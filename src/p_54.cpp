#include <bits/stdc++.h>

// #define DEBUG 0

enum Player { PLAYER1 = 0, PLAYER2 = 1, ERROR = -1 };

enum Levels { HC, OP, TP, TK, ST, FL, FH, FK, SF, RF };

std::map<char, int> vals{{'-', 0}};
std::map<char, int> suits;

std::map<Player, int> SCORES;

std::vector<char> C{'2', '3', '4', '5', '6', '7', '8',
                    '9', 'T', 'J', 'Q', 'K', 'A'};
std::vector<char> S{'H', 'S', 'C', 'D'};

typedef std::pair<int, char> Result;
typedef std::array<Result, 2> Result2;
typedef std::pair<Levels, int> Level;
typedef std::vector<std::string> Hand;

const Result DEF = {0, '-'};

std::ostream& operator<<(std::ostream& o, const Result& res) {
    o << "[" << res.first << " '" << res.second << "']";
    return o;
}

std::ostream& operator<<(std::ostream& o, const Result2& res) {
    if (res[0] == DEF) {
        o << "[None]";
    } else {
        o << "{" << res[0] << ", " << res[1] << "}";
    }
    return o;
}

void build() {
    for (int i = 0; i < (int)C.size(); i++) {
        vals[C[i]] = i + 2;
    }
    for (int i = 0; i < (int)S.size(); i++) {
        vals[S[i]] = 1;
    }
}

Result check_high_card(const Hand& hand, std::set<char> ignore = {}) {
    char max_c = '-';
    for (const auto& h : hand) {
        char c = h[0], s = h[1];
        if (ignore.count(c)) {
            continue;
        }
        if (vals[c] > vals[max_c]) {
            max_c = c;
        }
    }
    return {vals[max_c], max_c};
}

Result check_pair(const Hand& hand, std::set<char> ignore = {}) {
    std::map<char, int> mp;
    for (const auto& h : hand) {
        char c = h[0], s = h[1];
        if (ignore.count(c)) {
            continue;
        }
        mp[c]++;
    }
    char mx = '-';
    for (auto [c, cnt] : mp) {
        if (cnt == 2) {
            if (mx == '-' || vals[c] > vals[mx]) {
                mx = c;
            }
        }
    }
    return {vals[mx], mx};
}

Result check_two_pair(const Hand& hand, std::set<char> ignore = {}) {
    Result r1 = check_pair(hand);
    Result r2 = check_pair(hand, {r1.second});
    char p1 = r1.second, p2 = r2.second;
    if (p1 != '-' && p2 != '-') {
        char mx = vals[p1] > vals[p2] ? p1 : p2;
        return {vals[mx], mx};
    }
    return DEF;
}

Result check_three_kind(const Hand& hand) {
    std::map<char, int> mp;
    for (auto h : hand) {
        char c = h[0];
        mp[c]++;
    }
    for (auto [c, cnt] : mp) {
        if (cnt == 3) {
            return {vals[c], c};
        }
    }
    return DEF;
}

Result check_straight(const Hand& hand) {
    std::vector<int> values;
    for (auto h : hand) {
        values.push_back(vals[h[0]]);
    }
    std::sort(values.begin(), values.end());
    for (int i = 1; i < (int)values.size(); i++) {
        if (values[i] - values[i - 1] != 1) {
            return DEF;
        }
    }
    return check_high_card(hand);
}

Result check_flush(const Hand& hand) {
    std::map<char, int> mp;
    for (auto h : hand) {
        char s = h[1];
        if (++mp[s] == 5) {
            return {1, s};
        }
    }
    return DEF;
}

std::array<Result, 2> check_full_house(const Hand& hand) {
    std::array<Result, 2> res = {DEF, DEF};
    auto p = check_pair(hand);
    auto t = check_three_kind(hand);
    if (p.first == 0 || t.first == 0) {
        return res;
    }
    res[0] = p, res[1] = t;
    return res;
}

Result check_four_kind(const Hand& hand) {
    std::map<char, int> mp;
    for (auto h : hand) {
        mp[h[0]]++;
    }
    for (auto [c, cnt] : mp) {
        if (cnt == 4) {
            return {vals[c], c};
        }
    }
    return DEF;
}

Result check_straight_flush(const Hand& hand) {
    auto r1 = check_straight(hand);
    auto r2 = check_flush(hand);
    if (r1 == DEF || r2 == DEF) {
        return DEF;
    }
    return r1;
}

Result check_royal_flush(const Hand& hand) {
    auto r1 = check_straight_flush(hand);
    if (r1 == DEF || r1.second != 'A') {
        return DEF;
    }
    return r1;
}

void readHand(std::string s, Hand& hand) {
    std::stringstream ss(s);
    std::string card;
    while (ss >> card) {
        hand.push_back(card);
    }
}

void readHands(std::string game, Hand& p1, Hand& p2) {
    int sz = (3 * 5);
    readHand(game.substr(0, sz), p1);
    readHand(game.substr(sz), p2);
}

void printHand(const Hand& hand) {
    std::cout << "[";
    for (auto it : hand)
        std::cout << "'" << it << "', ";
    std::cout << "]\n";
}

Level evaluate(const Hand& hand) {
    printHand(hand);
    Result res;
    Result2 res2;
    if ((res = check_royal_flush(hand)) != DEF) {
        std::cout << "RyFl: " << check_royal_flush(hand) << "\n";
        return {RF, res.first};
    }

    if ((res = check_straight_flush(hand)) != DEF) {
        std::cout << "StFl: " << check_straight_flush(hand) << "\n";
        return {SF, res.first};
    }

    if ((res = check_four_kind(hand)) != DEF) {
        std::cout << "Four: " << check_four_kind(hand) << "\n";
        return {FK, res.first};
    }
    res2 = check_full_house(hand);
    if (res2[0] != DEF) {
        std::cout << "Fulh: " << check_full_house(hand) << "\n";
        return {FH, res2[1].first};
    }

    if ((res = check_flush(hand)) != DEF) {
        std::cout << "Flus: " << check_flush(hand) << "\n";
        return {FL, res.first};
    }

    if ((res = check_straight(hand)) != DEF) {
        std::cout << "Str8: " << check_straight(hand) << "\n";
        return {ST, res.first};
    }

    if ((res = check_three_kind(hand)) != DEF) {
        std::cout << "Thre: " << check_three_kind(hand) << "\n";
        return {TK, res.first};
    }

    if ((res = check_two_pair(hand)) != DEF) {
        std::cout << "TwoP: " << check_two_pair(hand) << "\n";
        return {TP, res.first};
    }

    if ((res = check_pair(hand)) != DEF) {
        std::cout << "Pair: " << check_pair(hand) << "\n";
        return {OP, res.first};
    }
    // std::cout << "RyFl: " << check_royal_flush(hand) << "\n";
    // std::cout << "StFl: " << check_straight_flush(hand) << "\n";
    // std::cout << "Four: " << check_four_kind(hand) << "\n";
    // std::cout << "Fulh: " << check_full_house(hand) << "\n";
    // std::cout << "Flus: " << check_flush(hand) << "\n";
    // std::cout << "Str8: " << check_straight(hand) << "\n";
    // std::cout << "Thre: " << check_three_kind(hand) << "\n";
    // std::cout << "TwoP: " << check_two_pair(hand) << "\n";
    // std::cout << "Pair: " << check_pair(hand) << "\n";
    // std::cout << "High: " << check_high_card(hand) << "\n";
    // std::cout << "\n";
    res = check_high_card(hand);
    std::cout << "High: " << check_high_card(hand) << "\n";
    return {HC, res.first};
}

Player get_winner(const Hand& p1, const Hand& p2) {
    Level l1 = evaluate(p1);
    Level l2 = evaluate(p2);
    std::cout << "Evaluate"
              << "\n";

    if (l1.first != l2.first) {
        std::cout << "Different Levels [" << l1.first << " " << l2.first
                  << "]: ";
        if (l1.first > l2.first) {
            std::cout << "P1\n";
            return PLAYER1;
        } else {
            std::cout << "P2\n";
            return PLAYER2;
        }
    }

    std::cout << "Same Level\n";
    if (l1.second != l2.second) {
        std::cout << "Different Card\n";
        if (l1.second > l2.second) {
            std::cout << "P1\n";
            return PLAYER1;
        } else {
            std::cout << "P2\n";
            return PLAYER2;
        }
    }

    int cnt = 0;
    char c1 = check_high_card(p1).second;
    char c2 = check_high_card(p2).second;

    std::cout << "Same Card: " << c1 << ", " << c2 << "\n";
    std::set<char> ignore_1;
    std::set<char> ignore_2;
    do {
        if (c1 != c2) {
            std::cout << "First Diff [" << c1 << ", " << c2 << "]\n";
            if (vals[c1] > vals[c2]) {
                std::cout << "P1\n";
                return PLAYER1;
            } else {
                std::cout << "P2\n";
                return PLAYER2;
            }
        }
        ignore_1.insert(c1);
        ignore_2.insert(c2);
        c1 = check_high_card(p1, ignore_1).second;
        c2 = check_high_card(p2, ignore_2).second;

        std::cout << "Same Card, Next [" << c1 << ", " << c2 << "]\n";
    } while (++cnt < 7);
    return ERROR;
}

void score_game(std::string game) {
    Hand p1, p2;
    readHands(game, p1, p2);

    Player winner = get_winner(p1, p2);

    SCORES[winner]++;

    if (winner == PLAYER1) {
        std::cout << "Player 1"
                  << "\n";
    } else if (winner == PLAYER2) {
        std::cout << "Player 2"
                  << "\n";
    } else {
        std::cout << "Error "
                  << "\n";
    }

    assert(winner != ERROR);
}

void test() {
    std::vector<std::string> games{
        "5H 5C 6S 7S KD 2C 3S 8S 8D TD", "5D 8C 9S JS AC 2C 5C 7D 8S QH",
        "2D 9C AS AH AC 3D 6D 7D TD QD", "4D 6S 9H QH QC 3D 6D 7H QD QS",
        "2H 2D 4C 4D 4S 3C 3D 3S 9S 9D", "5H KS 9C 7D 9H 8D 3S 5D 5C AH",
        "5H 6H 7H 8H 9H TS JS QS KS AS"};
    int cnt = 0;
    for (auto game : games) {
        std::cout << "=============================\n";
        std::cout << "GAME            " << ++cnt << "\n";
        std::cout << "-----------------------------\n";
        score_game(game);
        std::cout << "=============================\n";
    }
}

void run(std::string file_name = "54_poker.txt") { // change when passing arg
    std::ifstream in(file_name);

    std::string line;
    int cnt = 0;
    while (std::getline(in, line)) {
        if (line.size() > 10) {
            std::cout << "=============================\n";
            std::cout << "GAME            " << ++cnt << "\n";
            std::cout << "-----------------------------\n";
            score_game(line);
        }
    }
}

int main(int argc, char** argv) {
    build();

    if (argc > 1) {
        run();
    } else {
        test();
    }

    std::cout << "===========================\n";
    std::cout << "===========================\n";
    std::cout << "PLAYER 1: " << SCORES[PLAYER1] << "\n";
    std::cout << "PLAYER 2: " << SCORES[PLAYER2] << "\n";
    std::cout << "===========================\n";

    return 0;
}
