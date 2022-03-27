#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 *
 * [2028] 找出缺失的观测数据
 */

// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long mSums=0;
        for(auto &it:rolls) mSums+=it;
        long long nSums=mean*(rolls.size()+n)-mSums;

        vector<int> ret;

        /// 到现在为止,可以知道共有n个数字,和为m
        // 判断是否有解
        if(nSums<n) return ret;
        if(nSums>n*6) return ret;

        // cout<<mSums<<endl;
        // cout<<nSums<<endl;

        // 进行内容求解
        int begin=1;
        for(int i=1;i<=6;i++)
        {
            if(nSums>=i*n && nSums<(i+1)*n)
            {
                begin=i;
                break;
            }
        }

        // cout<<begin<<endl;

        int left=nSums-begin*n;
        ret.resize(n,begin);
        for(int i=0;i<left;i++)
        {
            ret[i]+=1;
        }
        return ret;
    }
};
// @lc code=end

