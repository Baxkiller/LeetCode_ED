/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include <bits/stdc++.h>
using namespace std;
// 91.32--9.04


// @lc code=start
class Solution {
public:
    void Sreverse(string &s)
    {
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            swap(s[i],s[j]);
        }
    }

    string reverseWords(string s) {
        if(s.length()==1) return s;

        string ret="";
        string tmp;
        stringstream ss;
        ss<<s;
        // 每次截断得到的内容放在tmp中
        while(getline(ss,tmp,' '))
        {
            Sreverse(tmp);
            ret+=tmp;
            ret+=' ';
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end

