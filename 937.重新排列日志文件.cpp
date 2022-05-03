/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
// 用大根堆排序!

bool isDigit(char c){return c>='0' && c<='9';}

bool Cmp(string a,string b)
{
    string biaoshia;
    string biaoshib;
    stringstream ss;
    stringstream ss2;
    ss<<a;
    ss2<<b;

    getline(ss,biaoshia,' ');
    getline(ss2,biaoshib,' ');
    getline(ss,a,'\0');
    getline(ss2,b,'\0');

    bool aDigit=isDigit(a[0]);
    bool bDigit=isDigit(b[0]);

    if(aDigit && bDigit)
        return false;
    if(aDigit && !bDigit)
        return false;
    if( !aDigit && bDigit)
        return true;
    // 两者都不是数字
    if(a==b)
        return biaoshia<biaoshib;
    else
        return a<b;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {// 字母单独排 可以利用map进行排序?
    // 剩下的数字不需要管
        stable_sort(logs.begin(),logs.end(),Cmp);
        return logs;
    }
};

// @lc code=end

