/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        // 相当于找到最大最小值 然后求两者的差值
        int maxNum=nums[0],minNum=nums[0];
        for(auto &it:nums)
        {
            maxNum=max(maxNum,it);
            minNum=min(minNum,it);
        }
        if(maxNum-minNum<=2*k)
            return 0;
        else
            return maxNum-minNum-2*k;
    }
};
// @lc code=end

