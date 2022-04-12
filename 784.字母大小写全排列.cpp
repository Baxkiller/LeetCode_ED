/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include <bits/stdc++.h>
using namespace std;
// 89.31--31.06
// @lc code=start
class Solution {
public:
    vector<string> ret;
    int limit;
    string words;
    // 小写标记不标记,大写标记为1
    void recursion(int index,int record)
    {
        if(index==limit)
        {
            int i=0;
            string res=words;
            while(record)
            {
                // 要转化为大写字母
                if(record&1)
                {
                    res[i]=res[i]-'a'+'A';
                }
                record>>=1;
                i++;
            }
            ret.push_back(res);
            return;
        }

        if(words[index] >='0' && words[index] <='9')
        {
            recursion(index+1,record);
            return;
        }

        // 原本是大写字母
        if(words[index] >='A' && words[index] <='Z')
        {// 先转化成小写
            words[index]=words[index]-'A'+'a';
        }

        recursion(index+1,record);
        record|=(1<<index);
        recursion(index+1,record);
    }
    vector<string> letterCasePermutation(string s) {
        // 类似于LeetCode 77
        // 这里还是采用递归+位记录
        limit=s.size();
        words=s;
        recursion(0,0);
        return ret;
    }
};
// @lc code=end

