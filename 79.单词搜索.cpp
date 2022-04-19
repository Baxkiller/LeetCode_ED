/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <bits/stdc++.h>
using namespace std;
// 应该使用深度优先搜索!!
// @lc code=start
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    vector<vector<int>> visit;
    int limit,m,n;
    vector<vector<char>> board;
    string word;
    bool dfs(int index,int x,int y)
    {// 从给定的点开始进行向下搜索
        // 保证当前正在搜索的点的位置是合法的且没有被搜索过的
        if(index==limit) return true;
        // x 和 y 代表当前正在搜索的点的位置
        // cout<<x<<" "<<y<<" "<<word[index]<<endl;
        int tx,ty;
        for(int i=0;i<4;i++)
        {
            tx=x+dx[i],ty=y+dy[i];
            if(tx<0 || tx >=m) continue;
            if(ty<0 || ty >=n) continue;

            if(visit[tx][ty]==0)
            {
                if(board[tx][ty]==word[index])
                {
                    visit[tx][ty]=1;
                    if(dfs(index+1,tx,ty))
                        return true;
                    visit[tx][ty]=0;
                }
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        char begin=word[0];
        this->m=board.size();
        this->n=board[0].size();

        visit.resize(m);

        this->board=board;
        this->word=word;
        this->limit=word.size();

        if(m*n < word.size()) return false;

        // 获取搜索开端
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(board[i][j]==begin)
                {
                    for(int i=0;i<m;i++) 
                    {
                        visit[i].clear();
                        visit[i].resize(n,0);
                    }
                    visit[i][j]=1;
                    if(dfs(1,i,j))
                        return true;
                }
        }

        return false;
    }
};
// @lc code=end

