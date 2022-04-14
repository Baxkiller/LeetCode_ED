/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */
#include <bits/stdc++.h>
using namespace std;
// 89--80
// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxRes=0;
        int m=accounts.size();
        int n=accounts[0].size();
        for(int i=m-1;i>=0;i--)
        {
            int tmp=0;
            for(int j=n-1;j>=0;j--)
            {
                tmp+=accounts[i][j];
            }
            maxRes=max(maxRes,tmp);
        }
        return maxRes;
    }
};
// @lc code=end

