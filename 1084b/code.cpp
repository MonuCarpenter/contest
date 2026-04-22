/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 05:16 PM IST
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
    for (int i = 0; i < n; i++) {
        log("input", i, a[i]);
        std::cin >> a[i];
    }

    if(n <= 1) { 
        std::cout << 0 << std::endl;
        return 0;
    }

    int result = 0; 

    for (int i = 0; i + 1 <= n; i++) {
        log("comparing", a[i], a[i + 1]);
        if(a[i] > a[i + 1]) { 
            log("matched", a[i], a[i + 1]);
            result++;
        }
    }

    std::cout << result << std::endl;
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
