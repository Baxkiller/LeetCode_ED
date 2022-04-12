/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <bits/stdc++.h>
using namespace std;
// 暴力方法竟然过了
// 5.24--5.06
// 通过优化,减小去重时间
// 28--36
// @lc code=start
// 仍然保持之前的想法
// 通过依次寻找检查数字来完成整体的功能
class Solution {
public:
    vector<int> can;
    vector<vector<int>> recursion(int num,int beginIndex)
    {
        vector<vector<int>> ret;
        if(num<can[0]) return ret;
        for(int i=beginIndex;i<can.size() && num>=can[i];i++)
        {
            vector<vector<int>> tmp=recursion(num-can[i],i);
            if(tmp.empty() && can[i]==num)
            {
                vector<int > t;
                t.push_back(can[i]);
                tmp.push_back(t);
            }
            else if(!tmp.empty())
            {
                for(auto &it:tmp) it.push_back(can[i]);
            }

            for(auto &it:tmp)
                ret.push_back(it);
        }
        return ret;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        can=candidates;
        vector<vector<int>> ret=recursion(target,0);
        // 需要手动去重?
        // for(auto &it:ret)
        //     sort(it.begin(),it.end());
        // sort(ret.begin(),ret.end());
        // auto it=unique(ret.begin(),ret.end());
        // vector<vector<int>> res(ret.begin(),it);
        return ret;
    }
};
// @lc code=end

