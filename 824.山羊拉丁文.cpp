/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
// 100--91
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkChar(char c)
    {
        // 转换为小写字母
        if(c>='A' && c<='Z') c=c-'A'+'a';
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        else
            return false;
    }
    string toGoatLatin(string sentence) {
        stringstream ss;
        ss<<sentence;
        string ret="";
        int index=1;
        while(getline(ss,sentence,' '))
        {
            if(!checkChar(sentence[0]))
            {
                ret+=sentence.substr(1);
                ret+=sentence[0];
            }
            else ret+=sentence;

            ret+="ma";
            for(int i=0;i<index;i++)
                ret+='a';
            ret+=' ';
            index++;
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end

