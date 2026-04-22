/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 01:32 AM IST
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
    float solve(int N) {
        int total = 2 * N;
        while (total--) {
            std::string name;
            int x, y;
            std::cin >> name >> x >> y;

             
        }
    }
};

main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // creating a sol object from the call
    Solution sol;

    int N;
    int test_case = 1;
    while (std::cin >> N && N != 0) {
        float result = sol.solve(N); 
        std::cout << "Case " << test_case << ":  " << result << std::endl;
        test_case++;
    }
    return 0;
}
