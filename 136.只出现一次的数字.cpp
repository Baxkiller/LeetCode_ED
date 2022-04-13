/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
//89--51.83
// 这个题非常巧妙!!
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto &it:nums)
            res^=it;
        return res;
    }
};
// @lc code=end

