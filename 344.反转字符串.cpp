/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
    //    reverse(s.begin(),s.end()); 
        int l=0,r=s.size()-1;
        char tmp;
        while(l<r)
        {
            tmp=s[r];
            s[r--]=s[l];
            s[l++]=tmp;
        }
    }
};
// @lc code=end

