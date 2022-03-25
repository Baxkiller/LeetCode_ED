#include <bits/stdc++.h>
using namespace std;

// 题解
// 妹想到直接暴力竟然能过 并且超过72.19%??
// 感觉dp才是正解

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string words;
    int isPalindrome(int index,int index2,string &tmp)
    {
        int len=0;
        if(index==index2)
        {
            len=1;
        }
        else
        {
            len=2;
        }
        int i,j;
        for(i=index-1,j=index2+1;i>=0 && j<words.size();i--,j++)
        {
            if(words[i]==words[j]) len+=2;
            else break;
        }
        // cout<<len<<":"<<i<<" "<<j<<endl;
        tmp=words.substr(i+1,len);
        return len;
    }
    string longestPalindrome(string s) {
        words=s;
        int maxLen=1,tmpRes=0;
        string ans="";
        ans+=s[0];
        string tmp="";
        for(int i=0;i<s.length();i++)
        {
            // 先初步检查,再仔细筛查
            if(i+1<s.length() && s[i]==s[i+1])
            {
                if(maxLen<(tmpRes=isPalindrome(i,i+1,tmp)))
                {
                    maxLen=tmpRes;
                    ans=tmp;
                }
            }
            if((i-1>=0) && (i+1)<s.size())
            {
                if(s[i-1]==s[i+1])
                {
                    if(maxLen<(tmpRes=isPalindrome(i,i,tmp)))
                    {
                        maxLen=tmpRes;
                        ans=tmp;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

