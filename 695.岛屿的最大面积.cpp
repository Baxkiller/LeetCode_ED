/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
// 也还是一个bfs
// 不过在搜索过程中需要注意
// 一旦搜索到一个岛屿
// 就要先停下手头的搜索,转而搜索这个小岛
// 就把这个岛屿完全搜索完毕!
// [[0,1],[1,0]]

#include <bits/stdc++.h>
using namespace std;
// 44.92--22.21
// @lc code=start
class Solution {
public:

    deque<pair<int,int>> pos;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    vector<vector<int>> visit;
    
    int CountIs(int x,int y,vector<vector<int>>& grid)
    {
        pos.emplace_front(x,y);
        int num=1;
        int tx,ty;
        while(!pos.empty())
        {
            x=pos.front().first;
            y=pos.front().second;
            if(grid[x][y]==0) return num;
            pos.pop_front();

            for(int i=0;i<4;i++)
            {
                tx=x+dx[i],ty=y+dy[i];
                // 合法性检测
                if(tx<0 || tx>=grid.size()) continue;
                if(ty<0 || ty>=grid[0].size()) continue;
                
                if(visit[tx][ty]==0) visit[tx][ty]=1;
                else continue;// 已经访问过了

                // 如果搜到了小岛,立刻转去进行小岛的面积求解!
                if(grid[tx][ty]==1)
                {
                    num++;
                    pos.emplace_front(tx,ty);
                }
                else
                {
                    pos.emplace_back(tx,ty);
                }
            }
        }
        return num;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        // 设定访问数组
        visit.resize(grid.size());
        for(int i=0;i<grid.size();i++)
            visit[i].resize(grid[0].size(),0);
        
        // 相关变量设定
        int ret=0;int tmpCnt=0;
        int CntIsland=1;

        int x,y,tx,ty,targetValue;

        // 从左上角的位置开始搜索
        pos.push_front(make_pair(0,0));
        visit[0][0]=1;
        if(grid[0][0]==1)
        {
            ret=max(ret,CountIs(0,0,grid));
        }

        // 搜索
        while(!pos.empty())
        {
            x=pos.front().first;
            y=pos.front().second;
            pos.pop_front();

            // 当前搜索的特点
            targetValue=grid[x][y];

            // 当前位置的四周搜索
            for(int i=0;i<4;i++)
            {
                tx=x+dx[i],ty=y+dy[i];

                // 合法性检测
                if(tx<0 || tx>=grid.size()) continue;
                if(ty<0 || ty>=grid[0].size()) continue;
                
                if(visit[tx][ty]==0) visit[tx][ty]=1;
                else continue;// 已经访问过了

                // 如果搜到了小岛,立刻转去进行小岛的面积求解!
                if(grid[tx][ty]==1)
                {
                    // pos.push_front(make_pair(tx,ty));
                    tmpCnt=CountIs(tx,ty,grid);
                    ret=max(ret,tmpCnt);
                }
                else
                {
                    pos.emplace_back(tx,ty);
                }
            }
        }

        // 尾部处理
        ret=max(ret,tmpCnt);

        // 返回结果
        return ret;

    }
};
// @lc code=end

