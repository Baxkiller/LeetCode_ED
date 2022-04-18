/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <bits/stdc++.h>
using namespace std;

// 感觉应该是可以用滑动窗口来解决
// 90
// @lc code=start
class Solution {
public:

    vector<int> cntT;
    vector<int> cntS;

    void getCnt(string s,vector<int> &cnt)
    {
        for(auto &c:s)
        {
            // 小写字母
            if(c-'A' >=26)
                c=c-'a'+26;
            else// 大写字母
                c-='A';
            cnt[c]++;
        }
        return;
    }

    bool checkCnt(char c)
    {
        if(c-'A'>=26)
            c=c-'a'+26;
        else
            c=c-'A';
        cntS[c]++;

        // 检查是不是满足条件了
        for(int i=0;i<52;i++)
        {
            if(cntS[i]<cntT[i]) return false;
        }
        return true;
    }

    // 尝试删除
    bool Minus(char c)
    {
        if(c-'A'>=26)
            c=c-'a'+26;
        else
            c=c-'A';
        cntS[c]--;

        return cntS[c]>=cntT[c];
    }

    bool Add(char c)
    {
        if(c-'A'>=26)
            c=c-'a'+26;
        else
            c=c-'A';
        cntS[c]++;
        return true;
    }

    string minWindow(string s, string t) {
        // 每次都要检查?
        if(s.size() < t.size()) return "";
        
        cntT.resize(52,0);
        cntS.resize(52,0);
        pair<int,int> ret;
        int minLength=0;

        // 先获取总的看对不对
        getCnt(t,cntT);
        
        // 使用双指针尝试逼近最终结果
        int l=0,r=0;
        // 先尝试找到第一个包含所有字母的位置
        while(r<s.size() && !checkCnt(s[r])) r++;
        // 此时的区间[l,r] 包含了t的所有
        // 或者根本不全
        if(r==s.size()) return "";
        
        minLength=r-l+1;
        while(r<s.size())
        {
            while(l<r && Minus(s[l])) l++;
            // 跳出循环时,刚好不满足
            // 此时的l仍然指在刚好满足的位置
            // cout<<"l="<<l<<endl;
            if(minLength>(r-l+1))
            {
                minLength=r-l+1;
                ret=make_pair(l,r);
            }

            //找到下一个刚才删除的字符的位置
            r++;
            while(r<s.size() && s[r]!=s[l])
            {
                Add(s[r]);
                r++;
            }
            l++;
            // 此时重新相等
            if(r==s.size()) // 没找到
                break;
            // 找到了 左指针再次移动
            Add(s[r]);
            // cout<<"r="<<r<<endl;
        }

        return s.substr(ret.first,minLength);
    }
};
// @lc code=end

