/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // 按照first和second分别进行排序
        vector<pair<int,int>> firsts;
        vector<pair<int,int>> seconds;
        vector<int> ret(intervals.size(),-1);
        firsts.reserve(intervals.size());
        seconds.reserve(intervals.size());
        int index=0;
        for(auto &it:intervals)
        {
            firsts.push_back(make_pair(it[0],index));
            seconds.push_back(make_pair(it[1],index));
            index++;
        }
        sort(firsts.begin(),firsts.end());
        sort(seconds.begin(),seconds.end());

        int pa=0,pb=0;
        while(pa< firsts.size() && pb<firsts.size())
        {
            if(firsts[pa].first>=seconds[pb].first)
            {
                int index=seconds[pb].second;
                ret[index]=firsts[pa].second;
                pb++;
            }
            else
                pa++;
        }
        return ret;
    }
};
// @lc code=end

