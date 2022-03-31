#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

/**
 * @brief 初始题解
int n;
    vector<string> ret;
    vector<int> cnt;
    // position决定了在当前的位置最多放置多少个右括号(合法性)
    // NumPut 表示在当前位置之前已经放置了多少个括号了
    // 当前position对应可以放置的
    void getResult(int NumPut,int position)
    {
        string tmp; 
        if(position==n)
        {
            // for(int i=1;i<=n;i++)
            //     cout<<cnt[i]<<" ";
            // cout<<endl;
            cnt[position]=n-NumPut;
            for(int i=1;i<=n;i++)
            {
                tmp+='(';
                for(int j=1;j<=cnt[i];j++)
                {
                    tmp+=')';
                }
            }
            ret.push_back(tmp);
        }
        else
        {
            for(int i=0;i<=position-NumPut;i++)
            {
                cnt[position]=i;
                getResult(NumPut+i,position+1);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        cnt.resize(n+1);
        getResult(0,1);
        sort(ret.begin(),ret.end());
        // auto pos=unique(ret.begin(),ret.end());
        // vector<string> rr(ret.begin(),pos);
        return ret;
    }
 * 
 */

// @lc code=start
class Solution {
public:
    int n;
    vector<string> ret;
    // position决定了在当前的位置最多放置多少个右括号(合法性)
    // NumPut 表示在当前位置之前已经放置了多少个括号了
    // 当前position对应可以放置的
    // tmp代表之前已经得到的内容
    void getResult(int NumPut,int position,string tmp)
    {
        if(position==n)
        {
            tmp+='(';
            for(int i=1;i<=n-NumPut;i++)
                tmp+=')';
            ret.push_back(tmp);
        }
        else
        {
            tmp+='(';
            for(int i=0;i<=position-NumPut;i++)
            {
                if(i) tmp+=')';
                getResult(NumPut+i,position+1,tmp);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        getResult(0,1,"");
        // sort(ret.begin(),ret.end());
        // auto pos=unique(ret.begin(),ret.end());
        // vector<string> rr(ret.begin(),pos);
        return ret;
    }
};
// @lc code=end

