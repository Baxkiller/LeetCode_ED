/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */
// 想法
// 一开始通过查看n中比特位为1的个数cnt来判断
// 添加剪枝,当比特位个数为2时,直接返回false,最后判断cnt==1?
// 50--32

// 当遇到某个bit位为1时,直接返回此时n右移一位后==0?
// 100--91

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n)
        {
            if(n&1)
            {
                n>>=1;
                return n==0;
            }
            else
                n>>=1;
        }
        return false;
    }
};
// @lc code=end

