/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <bits/stdc++.h>
// @lc code=start

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> _map; 

        for(int i=0; i<nums.size(); i++) {
            if(_map.count(target - nums[i]) > 0 &&  _map[target - nums[i]] != i) {
                return { _map[target - nums[i]], i};
            }
            _map[nums[i]] = i; 
        }
        return {}; 
    }
};
// @lc code=end
