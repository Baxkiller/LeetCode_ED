/*
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */
#include <bits/stdc++.h>
using namespace std;
// 不会做啊
// @lc code=start
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto cross=[](vector<int>&a,vector<int>&b,vector<int>&c){
            return (b[0]-a[0])*(c[1]-b[1])-(b[1]-a[1])*(c[0]-b[0]);
        };
        int n=trees.size();
        if(n<3)return trees;
        sort(begin(trees),end(trees),[](auto&a,auto&b){
            return make_pair(a[0],a[1])<make_pair(b[0],b[1]);
        });
        vector<vector<int>>low;
        for(auto&p:trees){
            while(low.size()>1 && cross(low[low.size()-1],low[low.size()-2],p)<0)low.pop_back();
            low.push_back(p);
        }
        reverse(begin(trees),end(trees));
        vector<vector<int>>top;
        for(auto&p:trees){
            while(top.size()>1 && cross(top[top.size()-1],top[top.size()-2],p)<0)top.pop_back();
            top.push_back(p);
        }
        set<pair<int,int>>s;
        for(auto&p:low)s.insert(make_pair(p[0],p[1]));
        for(auto&p:top)s.insert(make_pair(p[0],p[1]));
        vector<vector<int>>ans;
        for(auto[x,y]:s)ans.push_back({x,y});
        return ans;
    }
};
// @lc code=end

