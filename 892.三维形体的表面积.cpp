/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */
#include <bits/stdc++.h>
using namespace std; 

// @lc code=start
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    int surfaceArea(vector<vector<int>>& grid) {
        int bottom=0;
        int side=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                bottom+=2;
                side+=grid[i][j]*4;
                for(int t=0;t<4;t++)
                {
                    int tx=i+dx[t];
                    int ty=j+dy[t];
                    if(tx<0 || tx >=n) continue;
                    if(ty<0 || ty >=n) continue;
                    side-=min(grid[i][j],grid[tx][ty]);
                }
            }
        }
        return side+bottom;
    }
};
// @lc code=end

