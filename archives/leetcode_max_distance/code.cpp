/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 09:29 PM IST
 * Problem: <problem-name>
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifndef ONLINE_JUDGE
#include "../cpp-dump/cpp-dump.hpp"
#define log(...) cpp_dump(__VA_ARGS__)
template <> inline void cpp_dump::write_log(std::string_view output) {
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
  int maxDistance(std::string moves) {
    std::multiset<char> prev;
    int result = 0;

    std::unordered_map<char, char> mp = {
        {'U', 'D'},
        {'D', 'U'},
        {'L', 'R'},
        {'R', 'L'},
    };

    for (int i = 0; i < moves.size(); i++) {
      if (moves[i] == '_') {
        result++;
      } else if (moves[i] == 'U' && prev.contains('D') ||
                 moves[i] == 'D' && prev.contains('U') ||
                 moves[i] == 'R' && prev.contains('L') ||
                 moves[i] == 'L' && prev.contains('R')) {
        result--;
        auto element = prev.find(mp.at(moves[i]));
        prev.erase(element);
      } else {
        result++;
        prev.insert(moves[i]);
      }
    }
    return result;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;
  int max_distance = sol.maxDistance("UUUDD");

  std::cout << "Max Distance: " << max_distance << std::endl;
  return 0;
}
