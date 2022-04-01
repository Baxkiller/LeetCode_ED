#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    bool check(int n)
    {
        int t,tmp=n;
        while(n)
        {
            t=n%10;
            n/=10;
            if(t==0) return false;
            if(tmp%t!=0) return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(;left<=right;left++)
        {
            if(check(left))
                ret.push_back(left);
        }
        return ret;
    }
};
// @lc code=end

