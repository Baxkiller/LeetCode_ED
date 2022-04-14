/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <bits/stdc++.h>
using namespace std;

// 动态规划?
// 不是动态规划,是滑动窗口
// 就是动态规划
// 

/*
// 先来一发暴力求解 超时
        int preSum[nums.size()+1];
        preSum[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            preSum[i+1]=preSum[i]+nums[i];
        }

        // 然后二次遍历
        long long ret=INT32_MIN;
        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<i;j++)
                ret=max(ret,preSum[i]-preSum[j]);
        }
        // ret=max(ret,preSum[nums.size()-1]);
        return ret;
*/
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        // 前缀和肯定没错
        int n=nums.size();
        int preSum[n+1];
        preSum[0]=0;
        for(int i=0;i<n;i++)
            preSum[i+1]=preSum[i]+nums[i];
        
        int minPreSum=0;
        int ret=INT32_MIN;
        for(int i=1;i<=n;i++)
        {
            ret=max(preSum[i]-minPreSum,ret);
            if(preSum[i]<minPreSum) minPreSum=preSum[i];
        }
        return ret;
       
    }
};
// @lc code=end

