/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkIP6(string s)
    {
        stringstream ss;
        ss<<s;
        int cnt=0;
        if(s.back() == ':') return false;
        while(getline(ss,s,':'))
        {
            if(s.size() > 4 || s.size() < 1) return false;
            cnt++;
            for(auto &c:s)
            {
                if(c >'f' && c <='z') return false;
                if(c >'F' && c <='Z') return false; 
            }
        }
        if(cnt !=8 ) return false;
        return true;
    }
    bool checkIP4(string s)
    {
        stringstream ss;
        ss<<s;
        int cnt=0;

        if(s.back() == '.') return false;

        while(getline(ss,s,'.'))
        {
            int num=atoi(s.data());
            if(to_string(num)!=s) return false;
            if(num>255 || num < 0) return false;
            cnt++;
        }
        if(cnt !=4 )return false;
        return true;
    }
    string validIPAddress(string queryIP) {
        stringstream ss;
        ss<<queryIP;
        string tmp;
        getline(ss,tmp,'.');// 检查是否IP4格式
        if(tmp.size() == queryIP.size())
        {
        // 说明没有.存在  应该按照IP6进行解析判断
            if(checkIP6(queryIP))
                return "IPv6";
        }
        else
        {
            if(checkIP4(queryIP)) return "IPv4";
        }
        
        return "Neither";
    }
};
// @lc code=end

