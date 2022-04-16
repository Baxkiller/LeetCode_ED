/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */

  class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
      NestedInteger();
 
      // Constructor initializes a single integer.
      NestedInteger(int value);
 
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      bool isInteger() const;
 
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;
 
      // Set this NestedInteger to hold a single integer.
      void setInteger(int value);
 
      // Set this NestedInteger to hold a nested list and adds a nested integer to it.
      void add(const NestedInteger &ni);
 
      // Return the nested list that this NestedInteger holds, if it holds a nested list
      // The result is undefined if this NestedInteger holds a single integer
      const vector<NestedInteger> &getList() const;
  };
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class Solution {
public:
    string s;
    // 第一想法是能否通过递归实现?
    // NestedInteger recursion(int &index)
    // {
    //     //进行解析
    //     // 遇到左括号需要递归
    //     // bool inside=true;
    //     // if(s[index]!='[')
    //     //     inside=false;
    //     int t=0;
    //     bool minus=false;
    //     NestedInteger nt;

    //     for(;index<s.size();index++)
    //     {
    //         if(s[index]>='0' && s[index]<='9')
    //         {
    //             t*=10;
    //             t+=s[index]-'0';
    //             continue;
    //         }
    //         else if(s[index]==',')
    //         {
    //             if(s[index-1]==']') continue;

    //             if(minus) t=-t;
    //             nt.add(NestedInteger(t));
    //             t=0;
    //             minus=false;
    //             continue;
    //         }
    //         else if(s[index]=='-') minus=true;
    //         else if(s[index]=='[')
    //         {
    //             NestedInteger tmp;
    //             index++;
    //             tmp=recursion(index);
    //             nt.add(tmp);
    //         }
    //         else if(s[index]==']')
    //         {
    //             if(s[index-1]>='0' && s[index-1]<='9')
    //             {
    //                 if(minus) t=-t;
    //                 nt.add(NestedInteger(t));
    //                 t=0;
    //                 minus=false;
    //             }
    //             // index++;
    //             return nt;
    //         }
    //     }
    //     if(t!=0)
    //     {
    //         if(minus) t=-t;
    //         nt.add(NestedInteger(t));
    //     }
    //     return nt;
    // }

    int transToInter(int &index)
    {
        int ret=0;
        for(;index<s.size();index++)
        {
            if(s[index]>='0' && s[index]<='9')
            {
                ret*=10;
                ret+=s[index]-'0';
            }
            else
                return ret;
        }
        return ret;
    }

    NestedInteger recursion(int& index)
    {
        queue<NestedInteger> stk;
        bool minus=false;
        // if(s[index]=='[') index++;

        for(;index<s.size();index++)
        {
            if(s[index]=='-')
            {
                minus=true;
            }
            else if(s[index]>='0' && s[index]<='9')
            {
                if(minus)
                stk.push(NestedInteger(-transToInter(index)));
                else
                stk.push(NestedInteger(transToInter(index)));
                minus=false;
                index-=1;
            }
            else if(s[index]==',')
                continue;
            else if(s[index]=='[')
            {
                index++;
                stk.push(recursion(index));
            }
            else if(s[index]==']')
            {
                NestedInteger ret;
                while(!stk.empty())
                {
                    ret.add(stk.front());
                    stk.pop();
                }
                return ret;
            }
        }

        NestedInteger ret;
        while(!stk.empty())
        {
            ret.add(stk.front());
            stk.pop();
        }
        return ret;
    }

    NestedInteger deserialize(string s) {
        int index=0;
        this->s=s;

        if(s[0]!='[')
        {
            if(s[0]=='-')
                return -transToInter(++index);
            return transToInter(index);    
        }

        index++;
        NestedInteger ret;
        return recursion(index);
    }
};
// @lc code=end

