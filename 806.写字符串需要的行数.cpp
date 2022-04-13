/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */
#include <bits/stdc++.h>
using namespace std;

// 首先尝试暴力破解
// 100--48.88
// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int ret=1;
        int off=0;
        for(auto &c:s)
        {
            if(off+widths[c-'a']>100)
            {
                ret++;
                off=widths[c-'a'];
            }
            else
                off+=widths[c-'a'];
        }
        vector<int> res(2);
        res[0]=ret,res[1]=off;
        return res;
    }
};
// @lc code=end

