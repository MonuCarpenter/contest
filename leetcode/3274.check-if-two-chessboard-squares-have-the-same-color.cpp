/*
 * @lc app=leetcode id=3274 lang=cpp
 *
 * [3274] Check if Two Chessboard Squares Have the Same Color
 */

// @lc code=start
class Solution {
   public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int result1 = (coordinate1[0] - '0') + (coordinate1[1] - '0');
        bool br1 = result1 % 2 == 0;
        int result2 = (coordinate2[0] - '0') + (coordinate2[1] - '0');
        bool br2  = result2 % 2  == 0; 

        return br1 == br2; 
    }
};
// @lc code=end
