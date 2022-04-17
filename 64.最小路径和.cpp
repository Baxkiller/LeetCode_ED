/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <bits/stdc++.h>
using namespace std;
// 79--80
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        // 首先处理最上面的一行和最左面的一行
        for(int i=1;i<n;i++)
            grid[0][i]+=grid[0][i-1];

        for(int i=1;i<m;i++)
            grid[i][0]+=grid[i-1][0];
        
        // 从1,1开始进行dp
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        }
        return grid[m-1][n-1];
    }
};
// @lc code=end

