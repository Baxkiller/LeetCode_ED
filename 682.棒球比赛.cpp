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
        for(int i=0;i<ops.size();)
        {
            if(ops[i]=="C")
            {
                int nxt=i-1;
                ops.erase(ops.begin()+i);
                ops.erase(ops.begin()+i-1);
                i=nxt;
            }
            else if(ops[i]=="D")
            {
                ops[i]=to_string(atoi(ops[i-1].data())*2);
                i++;
            }
            else if(ops[i]=="+")
            {
                ops[i]=to_string(atoi(ops[i-1].data())+atoi(ops[i-2].data()));
                i++;
            }
            else
                i++;
        }
        long long ret=0;
        for(auto it:ops)
        {
            ret+=atoi(it.data());
        }
        return ret;
    }
};
// @lc code=end

