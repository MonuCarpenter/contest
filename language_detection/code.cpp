/*
 * Author: Monu Carpenter
 * Handle: m_o_n_u
 * Time: 02:10 PM IST
 * Problem: Language Detection */

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

class Solution {
public:
  std::string detect(std::string s) {
    if (s.find("HELLO") != std::string::npos)
      return "ENGLISH";
    else if (s.find("HOLA") != std::string::npos)
      return "SPANISH";
    else if (s.find("HALLO") != std::string::npos)
      return "GERMAN";
    else if (s.find("BONJOUR") != std::string::npos)
      return "FRENCH";
    else if (s.find("CIAO") != std::string::npos)
      return "ITALIAN";
    else if (s.find("ZDRAVSTVUJTE") != std::string::npos)
      return "RUSSIAN";
    else
      return "UNKNOWN";
  };
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Solution sol;

  std::string str;
  int index = 1;

  while (std::cin >> str) {
    if (str == "#")
      break;

    std::cout << "Case" << " " << index << ": " << sol.detect(str) << "\n";
    index++;
  }

  return 0;
}
