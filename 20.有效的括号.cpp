#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool checkLeft(char c)
    {
        return c=='{' || c=='[' || c=='(';
    }
    bool checkRight(char c)
    {
        return c=='}' || c==']' || c==')';
    }
    bool match(char a,char b)
    {
        // askii: () [\] {|}
        if(a+1==b || a+2==b) return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> sk;

        // 特判
        if(checkRight(s[0])) return false;
        
        for(auto &it:s)
        {
            if(sk.empty() || checkLeft(it))
            {
                sk.push(it);
            }
            else// 是right
            {
                if(!match(sk.top(),it)) return false;
                else sk.pop();
            }
        }
        if(!sk.empty()) return false;
        return true;
    }
};
// @lc code=end

