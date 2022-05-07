/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */
#include <bits/stdc++.h>
using namespace std;

// 初始判断是通过BFS或者DFS进行搜索?
// 每次内部搜索倾向:确定改变了的字母位置->
// 确定更改为哪个字母-> 更改后的字母是否有效
// 时间复杂度相对较高
/*
queue<string> cur;
// 如何防止重复访问? 创建一个答案空间 共4^8=64*1024个答案的可能
unordered_map<string,int> vis;

// 初始处理
cur.push(start);
vis[start]=1;
string tmpChar="ACTG";
int ans=0;

while(!cur.empty())
{
    string s=cur.front();
    cur.pop();
    
    if(s==end) return ans;
    else ans++;

    for(int i=0;i<8;i++)
    {
        char correct=s[i];
        for(int i=0;i<4;i++)
        {
            if(correct!=tmpChar[i])
            {
                s[i]=tmpChar[i];
                if(vis[s]!=0)
                {
                    vis[s]=1;
                    if(find(bank.begin(),bank.end(),s)!=bank.end())
                        cur.push(s);
                }
            }
            else
                continue;
        }
        s[i]=correct;
    }
}
return -1;
*/

// @lc code=start
class Solution {
public:
    bool check(string a,string b)
    {
        int diff=0;
        for(int i=0;i<8;i++)
        {
            if(a[i]!=b[i])
            {
                diff++;
                if(diff>=2) return false;
            }
        }
        if(diff==1) return true;
        else return false;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,int> routine;
        queue<string> valid;
        valid.push(start);
        routine[start]=1;

        int ans=0;

        while(!valid.empty())
        {
            int cnt=valid.size();
            ans++;

            while(cnt--)
            {
                string f=valid.front();
                valid.pop();

                if(f==end) return routine[f];

                for(auto &it:bank)
                {
                    if(routine[it]==0 && check(it,f))
                    {
                        routine[it]=ans;
                        valid.push(it);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

