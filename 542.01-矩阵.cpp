/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include <bits/stdc++.h>
using namespace std;
// a掉了!
// 时间击败18.79--13.45
// 是否要先将所有的0点加入??
// 加入后,将函数外变量更改到函数内
// 优化了vector的初始赋值
// 结果73.09--59.99

// @lc code=start
class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // 对于其中数值为0,那么新矩阵中对应位置也为0
        // 对于数值为1,需要进行搜索?
        // 设定一个dis结果矩阵
        // 从该矩阵搜索 非-1值,结果=值+
        // 初始化结果矩阵
        int tmpInt=mat[0].size();

        vector<vector<int>> ret(mat.size(),vector<int>(tmpInt,-1));
        // for(int i=0;i<mat.size();i++)
        //     ret[i].resize(tmpInt,-1);
        queue<pair<int,int>> pos;
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};


        // 从左上角进行搜索? x
        // 应该从第一个0的位置开始搜索
        // 首先搜索到第一个0的位置
        int x=-1,y=-1,tx=-1,ty=-1;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<tmpInt;j++)
            {
                if(mat[i][j]==0)
                {
                    pos.emplace(i,j);
                    ret[i][j]=0;
                }
            }
        }

        // 此时的x和y即0的位置,从该位置开始进行搜索
        while(!pos.empty())
        {
            x=pos.front().first;
            y=pos.front().second;
            pos.pop();

            for(int i=0;i<4;i++)
            {
                tx=x+dx[i],ty=y+dy[i];

                // 检查合法性
                if(tx<0 || tx>=mat.size()) continue;
                if(ty<0 || ty>=tmpInt) continue;
                
                if(ret[tx][ty]!=-1) continue;

                ret[tx][ty]=ret[x][y]+1;
                pos.emplace(tx,ty);
            }
        }
        return ret;
    }
};
// @lc code=end