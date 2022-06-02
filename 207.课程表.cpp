/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree;
        vector<vector<int>> graph;

        inDegree.resize(numCourses,0);
        graph.resize(numCourses);

        for(auto &it:prerequisites)
        {
            inDegree[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }

        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0) q.push(i);
        }

        vector<int> order;
        order.reserve(numCourses);

        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            order.push_back(f);
            for(auto it:graph[f])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                    q.push(it);
            }
        }

        return order.size() == numCourses;
    }
};
// @lc code=end

