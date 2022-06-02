/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.size()==1)
        {
            if(nums.front() < k) return 1;
            return 0;
        }
        if(k==0|| k==1) return 0;
        
        // 不需要排序  直接求解即可
        int pl=0,pr=1;
        int ret=0;
        long long multis=nums.front();
        while(pr<nums.size())
        {
            if(multis<k)
            {
                multis*=nums[pr];
                ret+=pr-pl;
                pr++;
            }
            else
            {// >=
                multis/=nums[pl];
                pl++;
            }
            // cout<<ret<<endl;
        }
        while(pl < nums.size() && multis >= k)
        {
            multis/=nums[pl];
            pl++;
        }
        ret+=pr-pl;
        return ret;
    }
};
// @lc code=end

