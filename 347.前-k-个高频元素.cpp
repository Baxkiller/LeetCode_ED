/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// 重温大根堆的用法?
// 47--29
// 是否存在更加高效的解法?

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 初始想法,先确定数频
        // 再通过大根堆获取
        map<int,int> cnts;
        for(auto &it:nums)
            cnts[it]++;
        priority_queue<pair<int,int>> orders;
        for(auto &it:cnts)
            orders.emplace(it.second,it.first);

        vector<int> ret;
        while(k--)
        {
            ret.push_back(orders.top().second);
            orders.pop();
        }
        
        return ret;
    }
};
// @lc code=end

