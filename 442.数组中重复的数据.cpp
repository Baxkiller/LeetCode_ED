/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==i+1) continue;
            while(nums[i]!=i+1)
            {
                if(nums[nums[i]-1]==nums[i])
                {
                    break;
                }
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            // cout<<nums[i]<<" ";
            if(nums[i]!=i+1)
                ret.push_back(nums[i]);
        }   
        return ret;
    }
};
// @lc code=end

