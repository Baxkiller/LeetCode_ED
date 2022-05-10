/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉 K 位数字
 */
/*  5.32--81.9
    void deleteOneChar(string &s,int &i)
    {
        i=max(0,i);
        for(;i<s.size()-1;i++)
        {
            if(s[i]>s[i+1])
            {
                s.erase(i,1);
                i--;
                return;
            }
        }
        s.pop_back();
    }
    string removeKdigits(string num, int k) {
        // 如何判定某位数字移除之后整体的值将会是最小的?
        // 从前向后,找到第一个大于前面的数字的位置
        int i=0;
        while(k--)
            deleteOneChar(num,i);
        if(num=="") return "0";
        // 检查是否存在前导0
        int index=0;
        while(num[index]=='0') index++;
        num=num.substr(index);
        if(num=="") return "0";
        else return num;
    }
*/
#include <bits/stdc++.h>
using namespace std;




//2 3 1 4
// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret;
        int index=0;
        while(k)
        {
            if(index>=num.size()) break;

            if(!ret.empty() && num[index]<ret.back())
            {
                ret.pop_back();
                k--;
                continue;
            }

            if(ret.empty() && num[index]=='0')
            {
                index++;
                continue;
            }

            ret.push_back(num[index]);
            index++;
        }
        if(index>=num.size())
        {
            while(k && !ret.empty())
            {
                k--;
                ret.pop_back();
            }
        }
        else
        {
            if(ret.empty())
                while(num[index]=='0') index++;
            ret+=num.substr(index);
        }

        if(ret=="") ret="0";
        return ret;
    }
};
// @lc code=end

