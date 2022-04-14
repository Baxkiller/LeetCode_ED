/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
// 49.32--45.00
// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int index=32;
        int ret=0;
        while(index--)
        {
            ret<<=1;
            ret|=n&1;
            n>>=1;
        }
        return ret;
    }
};
// @lc code=end

