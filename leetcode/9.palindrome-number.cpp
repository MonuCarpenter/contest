/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
#include <bits/stdc++.h>
// @lc code=start
class Solution {
   public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);

        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
// @lc code=end
