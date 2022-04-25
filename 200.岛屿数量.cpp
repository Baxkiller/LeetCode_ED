/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <bits/stdc++.h>
using namespace std;

// 应该是一个广度优先搜索的问题
// 89--14
// @lc code=start
int islandIndex=1e5;
class Solution {
public:
    vector<vector<char>>* grid_pointer;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int m,n;
    void recursion(int x,int y)
    {// 认为x和y点为起始点的岛屿
        // 广度优先还是深度优先呢
        queue<pair<int,int>> pos;
        pos.emplace(x,y);
        grid_pointer->data()[x][y]='2';
        while(!pos.empty())
        {
            x=pos.front().first;
            y=pos.front().second;
            pos.pop();
            for(int i=0;i<4;i++)
            {// 首先检查点的合法性
                int tx=x+dx[i];
                int ty=y+dy[i];

                if(tx<0 || tx >=m) continue;
                if(ty<0 || ty >=n) continue;
                
                if(grid_pointer->data()[tx][ty]=='1')
                {// 只有没被访问过才进行下一次访问
                    grid_pointer->data()[tx][ty]='2';
                    pos.emplace(tx,ty);
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        grid_pointer=&grid;
        m=grid.size();
        n=grid[0].size();

        //进行遍历
        int ret=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid_pointer->data()[i][j]=='1')
                {
                    ret++;
                    recursion(i,j);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

