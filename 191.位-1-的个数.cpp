/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
// 100--99.64

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n) 
        {
            if(n&1) ret++;
            n>>=1;
        }
        return ret;
    }
};
// @lc code=end

