#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int cur=0;
        while (cur<s.length() && (s[cur]<'0' || s[cur]>'9')) cur++;
        int tmp=0;
        for(int i=0;i<cur;i++)
        {
            if(i==cur-1)
            {
                if(s[i]=='+' || s[i]=='-' || s[i]==' ') continue;
                else return 0;
            }
            else
            {
                if(s[i]!=' ') return 0;
                else continue;
            }
        }


        bool minus=cur>0?(s[cur-1]=='-'):false;
        while(cur<s.length() && s[cur]=='0') cur++;
        long long ret=0;
        while(cur <s.length())
        {
            if(s[cur] >='0' && s[cur] <='9')
            {
                ret*=10;
                ret+=s[cur]-'0';
                cur++;
                if(ret >INT32_MAX) break;
            }
            else
                break;
        }
        if(minus)
            ret=-ret;
        if(ret>=INT32_MIN && ret <=INT32_MAX) return ret;
        else
            return ret<INT32_MIN?INT32_MIN:INT32_MAX;
    }
};
// @lc code=end

