/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include <bits/stdc++.h>
using namespace std;
// 常规解法
/* 70
vector<int> count(nums.size(),0);
for(auto &it:nums)
    count[it-1]++;

vector<int> ret;
for(int i=0;i<nums.size();i++)
{
    if(count[i]==0)
        ret.push_back(i+1);
}
return ret;
*/
// 新解法 51
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 新解法
        int n=nums.size();
        vector<int> ret;
        for(int i=0;i<n;i++)
        {
            while(nums[i]!=i+1)
            {
                if(nums[i]<i+1)
                {
                    ret.push_back(i+1);
                    break;
                }
                if(nums[nums[i]-1]==nums[i])
                    break;
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        // for(int i=nums.size()-1;i>=0;i--)
        //     if(nums[i]!=i+1) ret.push_back(i+1);
        return ret;
    }
};
// @lc code=end

