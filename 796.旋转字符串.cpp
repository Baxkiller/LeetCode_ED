/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */
#include <bits/stdc++.h>
using namespace std;
//100--18.23
// @lc code=start
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string tmp=s+s;
        int n=goal.size();
        for(int i=0;i<s.size();i++)
        {
            if(tmp.substr(i,n)==goal) return true;
        }
        return false;
    }
};
// @lc code=end

