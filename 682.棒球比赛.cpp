#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int idex=0;
        int ret=0;
        int tmp;
        vector<int> Nums(ops.size(),0);
        for(auto it:ops)
        {
            if(it[0]=='C')
                Nums.pop_back();
            else if(it[0]=='+')
            {
                idex=Nums.size()-1;
                Nums.push_back(Nums[idex]+Nums[idex-1]);
            }
            else if(it[0]=='D')
                Nums.push_back(Nums.back()*2);
            else
                Nums.push_back(atoi(it.data()));
        }
        for(auto it:Nums) ret+=it;
        return ret;
    }
};
// @lc code=end

