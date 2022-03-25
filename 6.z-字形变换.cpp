#include <bits/stdc++.h>
using namespace std;

// 解法2 100%-97.14%
// 观察规律,逐行求解,大体分为第一行内容和中间内容和最后一行的内容
// 也就是最后存在的这个解法

// 解法1 77.5%-46.99%
// 一个pattern中的字符个数
// // 共计有多少个完整的pattern
// if(s.length()<=numRows || numRows==1) return s;

// vector<string> perRow(numRows,"");
// int cntPerPattern=numRows*2-2;
// int numPettern=s.length()/cntPerPattern;
// int step=cntPerPattern;
// for(int i=1;i<=numPettern;i++)
// {
//     int begin=step*(i-1);
//     int end=begin+numRows-1;
//     perRow[0].push_back(s[begin]);
//     for(int j=1;j<numRows-1;j++)
//     {
//         perRow[j].push_back(s[begin+j]);
//         perRow[j].push_back(s[end*2-begin-j]);
//     }
//     perRow[numRows-1].push_back(s[end]);
// }
// // 处理不成个的pattern
// int cntLast=s.length()%(numRows*2-2);
// int begin=step*numPettern;
// // int end=begin+numRows-1;
// for(int i=0,ri=0;i+begin<s.length();i++)
// {
//     if(i>=numRows) ri=2*numRows-2-i;
//     else ri=i;
//     perRow[ri].push_back(s[begin+i]); 
// }
// string res="";
// for(int i=0;i<numRows;i++)
//     res+=perRow[i];
// return res;
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.length()<numRows) return s;

        string res="";
        // 新的求解方法,逐行求解,然后加起来
        int elePerPattern=2*numRows-2;

        // 第一行
        for(int i=0;i<s.length();i+=elePerPattern)
        {
            res+=s[i];
        }
        // 中间各行的内容
        int tmp=2*numRows;
        int idx=0;
        for(int i=1;i<numRows-1;i++)
        {
            for(int j=i;j<s.length();j+=elePerPattern)
            {
                res+=s[j];
                idx=tmp-2-2*i+j;
                if(idx<s.length())
                    res+=s[idx];
            }
        }
        // 最后一行
        for(int i=numRows-1;i<s.length();i+=elePerPattern)
        {
            res+=s[i];
        }
        return res;
    }
};
// @lc code=end

