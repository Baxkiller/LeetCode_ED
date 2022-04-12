/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <bits/stdc++.h>
using namespace std;
// 25.36--7.39
// 将数组改为使用vector<vector<int>> 后
// 程序运行时间打败100
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++)
            dp[i].resize(2,0);

        dp[0][0]=0;
        dp[0][1]=nums[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }

        return max(dp[n-1][0],dp[n-1][1]);
    }
};
// @lc code=end

