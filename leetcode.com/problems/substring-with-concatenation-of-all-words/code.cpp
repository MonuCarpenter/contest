/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 10:07 AM IST
 * Problem: substring-with-concatenation-of-all-words
 */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef MONU_LOCAL_JUDGE
#include "../../../cpp-dump/cpp-dump.hpp"
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
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    if (s.empty() || words.empty())
      return {};
    int L = words[0].size();
    int n = words.size();
    int total = n * L;
    if ((int)s.size() < total)
      return {};

    std::unordered_map<std::string, int> need;
    for (auto &w : words)
      need[w]++;

    std::vector<int> result;

    // Try each alignment mod L: window slides word-by-word in O(s.size())
    for (int offset = 0; offset < L; offset++) {
      std::unordered_map<std::string, int> window;
      int left = offset;
      int count = 0;
      for (int right = offset; right + L <= (int)s.size(); right += L) {
        std::string w = s.substr(right, L);
        auto it = need.find(w);
        if (it == need.end()) {
          window.clear();
          count = 0;
          left = right + L;
          continue;
        }
        window[w]++;
        count++;
        while (window[w] > it->second) {
          std::string lw = s.substr(left, L);
          window[lw]--;
          left += L;
          count--;
        }
        if (count == n) {
          result.push_back(left);
          // slide left by one word to find overlapping answers
          std::string lw = s.substr(left, L);
          window[lw]--;
          left += L;
          count--;
        }
      }
    }

    return result;
  }
};

int main() {
  CPP_DUMP_SET_OPTION(es_style, cpp_dump::types::es_style_t::no_es);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s = "barfoothefoobarman";
  std::vector<std::string> words = {"foo", "bar"};

  Solution sol;
  std::vector<int> result = sol.findSubstring(s, words);

  log(result);
  return 0;
}
