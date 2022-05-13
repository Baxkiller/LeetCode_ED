/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */
#include <bits/stdc++.h>
using namespace std;
// 感觉就是一个简单的遍历?
// 时间复杂度O(len*n)
// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int m=strs[0].size();
        int n=strs.size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]<strs[j-1][i])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

