#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
// 两个方法:直接排序
//         双指针与二分查找

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int index_min=1e5;
        for(auto &it:nums)
        {
            if(nums[index_min]<=it)
            
            it=it*it;
        }
    }
};
// @lc code=end

