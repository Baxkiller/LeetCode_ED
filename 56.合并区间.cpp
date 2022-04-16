/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <bits/stdc++.h>
using namespace std;
// 78.59
// vector<vector<int>>& intervals;
// 这他妈什么锤子样例,[[1,4],[0,0]]  [0,0]能算区间???
// 完全无极鲅鱼
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 特例处理
        if(intervals.size()<=1)
            return intervals;
        // 记得在上程设课的时候做过类似的题
        // 借鉴了差分数组用来记录
        map<int,int> nums;
        for(auto &it:intervals)
        {
            nums[it[0]]++;
            nums[it[1]]--;
        }
        vector<vector<int>> ret;
        int tmpSum=0;
        int First=-1;
        for(auto &it:nums)
        {
            tmpSum+=it.second;
            if(tmpSum>=1 && First==-1)
            {
                First=it.first;
            }
            else if(tmpSum<1 && First !=-1)
            {
                ret.push_back({First,it.first});
                First=-1;
            }
            else if(tmpSum==0 && First==-1)
            {
                ret.push_back({it.first,it.first});
            }
        }
        return ret;
    }
};
// @lc code=end

