/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        unsigned long long i=0;
        for(i=0;i*i<=x;i++);
        return i-1;
    }
};
// @lc code=end

