/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
         // 从给定的字符串开始向后遍历
         int len=s.size();
         if(s.size() !=goal.size()) return false;
         int pos[26];
         memset(pos,-1,sizeof(pos));
         int pos1=-1,pos2=-1;
         bool repeat=false;
         for(int i=0;i<len;i++)
         {
             if(s[i]!=goal[i])
             {
                 if(pos1==-1) pos1=i;
                 else if(pos2==-1) pos2=i;
                 else return false;
             }
             if(pos[s[i]-'a']!=-1) repeat=true;
             else pos[s[i]-'a']=i;
         }
         if(pos1==-1)
         {// 应该确定是否有重复的字母 如果有 返回true
            return repeat;
         }
         if(pos2==-1) return false;
         
         if(s[pos1]==goal[pos2] && s[pos2]==goal[pos1])
            return true;
        return false;
    }
};
// @lc code=end

