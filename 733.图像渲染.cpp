/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include <bits/stdc++.h>
using namespace std;

// 一个简单的广度优先搜素BFS
// 需要考虑边界问题
// 避免无限扩散,加入visit数组进行标识
/*
[[0,0,0],[0,1,1]]
1
1
1
*/

// 时间8ms 71.3  38.41

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int,int>> todo;

        int visit[image.size()][image[0].size()];
        for(int i=0;i<image.size();i++)
            memset(visit[i],0,sizeof(visit[i]));

        todo.push(make_pair(sr,sc));
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};

        int source=image[sr][sc];
        int tx=0,ty=0;

        pair<int,int> cur;
        while(!todo.empty())
        {
            cur=todo.front();
            todo.pop();
            int x=cur.first,y=cur.second;
            image[x][y]=newColor;

            for(int i=0;i<4;i++)
            {
                // 当前正在处理的元素
                tx=x+dx[i],ty=y+dy[i];
                // 检查合法性
                if(tx<0 || tx >=image.size()) continue;
                if(ty<0 || ty >=image[0].size()) continue;

                if(visit[tx][ty]==0)
                    visit[tx][ty]=1;
                else
                    continue;

                if(image[tx][ty]==source)
                {
                    todo.push(make_pair(tx,ty));
                }
            }
        }
        return image;
    }
};
// @lc code=end

