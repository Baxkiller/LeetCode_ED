/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// bfs 100
#include <bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cnt(s.size(),-1);
        queue<int> pos;
        for(int i=0;i<s.size();i++)
            if(s[i]==c)
            {
                pos.push(i);
                cnt[i]=0;
            }
        
        while(!pos.empty())
        {
            int n=pos.size();
            while(n--)
            {
                int a=pos.front();
                pos.pop();

                if(a-1 >=0)
                {
                    if(cnt[a-1]==-1)
                    {
                        cnt[a-1]=cnt[a]+1;
                        pos.push(a-1);
                    }
                }
                if(a+1<s.size() && cnt[a+1]==-1)
                {
                    cnt[a+1]=cnt[a]+1;
                    pos.push(a+1);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

