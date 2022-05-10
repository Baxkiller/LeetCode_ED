/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    string s;
    int parseInt(int &index)
    {
        int initNum=s[index++]-'0';
        while(s[index]>='0' && s[index]<='9')
        {
            initNum*=10;
            initNum+=s[index++]-'0';
        }
        return initNum;
    }
    string decode(int& index)
    {
        string tmp;
        string insideString="";
        int xishu=0;

        for(;index<s.size();)
        {
            if(s[index]>='0' && s[index]<='9')
            {
                xishu=parseInt(index);
                if(s[index]=='[')
                {
                    insideString=decode(++index);
                    while(xishu--)
                        tmp+=insideString;
                }
            }
            else if(s[index]==']')
            {
                index++;
                return tmp;
            }
            else
                tmp+=string(1,s[index++]);
            // cout<<index<<endl;
        }
        return tmp;
    }
    string decodeString(string s) {
        int index=0;
        this->s=s;
        return decode(index);
    }
};
// @lc code=end

