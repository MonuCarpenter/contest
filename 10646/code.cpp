/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:17 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <>
inline void cpp_dump::write_log(std::string_view output) {
    std::cout << output << '\n';
}
#else
#define log(...)
#define CPP_DUMP_SET_OPTION(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT(...)
#define CPP_DUMP_DEFINE_EXPORT_OBJECT_GENERIC(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM(...)
#define CPP_DUMP_DEFINE_EXPORT_ENUM_GENERIC(...)
#endif

class Solution {
   public:
    int get_value(std::string s) {
        char c = s[0];
        int cn = c - '0';
        return cn < 10 && cn >= 0 ? cn : 10;
    }
    std::string card_game() {
        std::string cards[52];

        for (int i = 0; i < 52; i++) {
            std::cin >> cards[i];
        }

        int first_number = 10 - get_value(cards[0]);
        int second_number = 25 + first_number;
        int third_number = 10 - get_value(cards[second_number]);
        return cards[first_number + second_number + third_number - 1];
    }
};

int main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    Solution sol;

    for (int i = 1; i <= t; i++) {
        std::string result = sol.card_game();
        std::cout << "Case " << i << ": " << result << std::endl;
    }
    return 0;
}
