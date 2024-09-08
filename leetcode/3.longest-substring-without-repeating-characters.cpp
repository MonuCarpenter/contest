/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
   public:
    int getMax(string s, int i, int j) {
        unordered_map<int, int> _map;
        for (int k = i; k <= j; i++) {
            if (_map.count(s[k]) > 0) {
                _map[s[k]]++;
            } else {
                _map[s[k]] = 1;
            }
        }

        for(auto s: _map) {
            if(s.second > 1) {
                return 0;
            }
        }
        return _map.size(); 
    }
    
    int lengthOfLongestSubstring(string s) {
        int maxL = INT_MIN;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < i == 0 ? s.size() - 1 : s.size(); i++) {
                int maxWords = getMax(s, i, j);
                if (maxWords > maxL) {
                    maxWords = maxL;
                    start = i;
                    end = j;
                }
            }
        }
    }
};
// @lc code=end
