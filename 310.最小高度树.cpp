#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
const int MaxN=3*1e4;

class Solution {
public:
    int degrees[MaxN];
    vector<vector<int>> e; 
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;
        // 特判
        if(n==1)
        {
            ret.push_back(0);
            return ret;
        }
        else if(n==2)
        {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }


        memset(degrees,0,sizeof(degrees));
        e.resize(n);
        for(auto &it:edges)
        {
            degrees[it[0]]++;
            degrees[it[1]]++;
            e[it[0]].push_back(it[1]);
            e[it[1]].push_back(it[0]);
        }
        queue<int> nodes;
        for(int i=0;i<n;i++)
        {
            if(degrees[i]==1)
            {
                nodes.push(i);
                degrees[i]--;
            }
        }
        int currentTime=2;
        while(!nodes.empty())
        {// 如果nodes非空 不断循环找到下一层的内容放进去
            int count=nodes.size();
            ret.clear();
            while(count--)
            {
                int i=nodes.front();
                nodes.pop();
                for(auto &it:e[i])
                {
                    degrees[it]--;
                    // 如果成为了叶子节点
                    if(degrees[it]==1)
                    {
                        nodes.push(it);
                        // cout<<it<<endl;
                    }
                }
                ret.push_back(i);
            }
            currentTime++;
        }
        return ret;
    }
};
// @lc code=end

