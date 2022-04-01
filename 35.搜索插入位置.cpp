/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,mid=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
            else
                return mid;
        }
        return left;
    }
};
// @lc code=end

