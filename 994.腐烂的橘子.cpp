/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */
#include <bits/stdc++.h>
using namespace std;

// 扩散问题 想到使用bfs,每次清空一个queue代表time ticks
// 53--92
// 将 if(grids[i][j]!=1)...if(girds[i][j]==1) 更改为
//    if(grids[i][j]!=1)...else
// 100-93
// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timeTick=0;
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<int,int>> pos;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                {
                    pos.emplace(i,j);
                    grid[i][j]=-1;// 证明已经访问过了
                }
            }
        }

        int x,y,tx,ty;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!pos.empty())
        {
            int cnt=pos.size();
            timeTick++;
            while(cnt--)
            {
                x=pos.front().first;
                y=pos.front().second;
                pos.pop();
                for(int i=0;i<4;i++)
                {
                    tx=x+dx[i],ty=y+dy[i];
                    
                    if(tx<0 || tx >= rows) continue;
                    if(ty<0 || ty >= cols) continue;

                    if(grid[tx][ty]!=1) continue;
                    else
                    {
                        pos.emplace(tx,ty);
                        grid[tx][ty]=-1;
                    }
                }
            }
        }
        if(timeTick)
            timeTick--;
        
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
                if(grid[i][j]==1) return -1;
        return timeTick;
    }
};
// @lc code=end

