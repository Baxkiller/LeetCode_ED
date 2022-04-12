/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
// 93.86--63.69
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size(),0);
        int n=triangle.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(j==0) dp[j]=dp[j]+triangle[i][0];
                else if(j==i) dp[j]=dp[j-1]+triangle[i][j];
                else
                {
                    dp[j]=min(dp[j],dp[j-1])+triangle[i][j];
                }
            }
        }
        int ret=dp[0];
        for(int i=1;i<n;i++)
            ret=min(ret,dp[i]);
        return ret;
    }
};
// @lc code=end

