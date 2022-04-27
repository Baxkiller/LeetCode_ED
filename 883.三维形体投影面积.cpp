/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int bot=0,right=0,ahead=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int> maxInCol(n,0);
        int tmp=0;
        for(int i=0;i<m;i++)
        {
            // right+=max(line_row)
            // ahead+=max(line_col)
            tmp=0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0) bot++;
                maxInCol[j]=max(maxInCol[j],grid[i][j]);
                tmp=max(tmp,grid[i][j]);
            }
            right+=tmp;
        }
        for(auto &it:maxInCol)
            ahead+=it;
        return ahead+bot+right;
    }
};
// @lc code=end

