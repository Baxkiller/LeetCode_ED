/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <bits/stdc++.h>
using namespace std;
// 95.77-41.83
// @lc code=start
class Solution {
public:
    bool Equal(vector<int> &a,vector<int> &b)
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    // 移动s1窗口大小的滑动窗口,看数量是否一致
    // 每次移动窗口,都要查看一遍有没有可能相同
    bool checkInclusion(string s1, string s2) {
        // 特判
        if(s1.length()>s2.length()) return false;


        vector<int> count1(26,1);
        vector<int> count2(26,1);

        // 初始化s1的字符串计数
        for(auto &it:s1)
            count1[it-'a']++;
        
        // s2窗口内计数的初始化
        int l=0;int r=s1.size()-1;
        for(int i=0;i<r;i++)
            count2[s2[i]-'a']++;

        // 设定滑动窗口进行移动
        // 每次移动都要检查
        while(r<s2.size())
        {
            count2[s2[r]-'a']++;
            if(Equal(count1,count2)) return true;
            
            // 如果两者不相同,滑动窗口右移
            count2[s2[l]-'a']--;
            l++,r++;
        }
        return false;
    }
};
// @lc code=end

