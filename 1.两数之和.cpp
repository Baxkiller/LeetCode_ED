/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]+nums[j])==target)
                {
                    res.push_back(j);
                    res.push_back(i);
                    return res;
                }
                else
                    continue;
            }
        }
        return res;
    }
};
// @lc code=end