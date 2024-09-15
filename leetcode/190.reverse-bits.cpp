/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            // Extract the rightmost bit of n
            uint32_t bit = (n >> i) & 1;
            // Shift the extracted bit to its reversed position and OR it with the result
            result |= bit << (31 - i);
        }
        return result;
    }
};
// @lc code=end
