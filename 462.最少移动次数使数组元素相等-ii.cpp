/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */
#include <bits/stdc++.h>
using namespace std;
// [1,89,32,5,-100,1086]
// @lc code=start
class Solution {
public:
    long long moveCounts(vector<int>& nums,int mid)
    {
        long long ret=0;
        for(auto &it:nums)
            ret+=abs(mid-it);
        return ret;
    }
    int minMoves2(vector<int>& nums) {
        map<int,int> numsCnt;
        for(auto &it:nums)
            numsCnt[it]++;
          
        int minEle=numsCnt.begin()->first;
        long long firCnt=moveCounts(nums,minEle);
        lessThan=numsCnt.begin()->second;
        moreThan=nums.size()-lessThan;
        int preVal=minEle;

        auto it=numsCnt.begin();
        it++;
        for(;it!=numsCnt.end();it++)
        {
            long long plus=lessThan*(it->first-preVal);
            long long minus=moreThan*(it->first-preVal);
            lessThan+=it->second;
            moreThan-=it->second;
            preVal=it->first;
            if(plus-minus<0)
            {
                firCnt+=plus-minus;
                continue;
            }
            else
            {
                // cout<<it->first<<endl;`
                return firCnt;
            }
        }
        return firCnt;

    }

    private:
        int lessThan;
        int moreThan;
};
// @lc code=end

