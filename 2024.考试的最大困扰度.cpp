#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// 菜狗经典开始没任何思路可言
// 看了投票top1的题解
// 大致理解了思路
// 相当于找包含了最多k个字符c的字符集最长的长度

// @lc code=start
class Solution {
public:
    string given;
    int k;
    int getCnt(char c)
    {
        int limit=given.size();
        int cnt_c=0;
        int maxlen=0;
        int l,r;
        for(l=0,r=0;l<=r && r<limit;r++)
        {
            if(given[r]==c)
                cnt_c++;
            if(cnt_c>k)
            {
                maxlen=max(maxlen,r-l);
                while(cnt_c>k)
                {
                    if(given[l]==c) cnt_c--;
                    l++;
                }
            }
        }
        maxlen=max(maxlen,r-l);
        // cout<<"maxLen:"<<c<<"\t"<<maxlen<<endl;
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        given=answerKey;
        this->k=k;
        return(max(getCnt('T'),getCnt('F')));
    }
};
// @lc code=end

