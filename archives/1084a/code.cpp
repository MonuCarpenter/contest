/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 06:23 PM IST
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

int solve() {
    int n; std::cin >> n; 
    
    int a[n]; 
    int max = INT_MIN; 

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] > max) {
            max = a[i];
        }
    }

    int max_count = 0; 

    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            max_count++;
        }
    }

    std::cout << max_count << std::endl;
    return 0;
}

int main() {
    CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
