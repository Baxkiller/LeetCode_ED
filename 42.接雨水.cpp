/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
// 初始想法是错误的
// 也就是分段的思想  只适用于第一个例子
/*
// map
        vector<pair<int,int>> pos;
        int n=height.size();
        vector<int> chafen(n+1,0);
        int pre=0;

        // 获得差分数组
        for(int i=1;i<n;i++)
            chafen[i]=height[i]-height[i-1];
        chafen[0]=height[0];
        chafen[n]=-height[n-1];
        
        // 找到第一个开始下降的位置
        int i=0;
        for(;i<=n && chafen[i]>=0;i++);
        pre=i-1;

        // 找到合适的位置
        for(;i<=n;i++)
        {
            if(chafen[i]<=0 && chafen[i-1]>0)
            {
                pos.push_back(make_pair(pre,i-1));
            }
            if(chafen[i]<0 && chafen[i-1]>=0)
                pre=i-1;
        }

        // 进行计算
        int ret=0;
        int h,w;
        for(auto &it:pos)
        {
            h=min(height[it.first],height[it.second]);
            for(int i=it.first+1;i<it.second;i++)
                ret+=h-height[i];
        }
        return ret;
*/
// Accept
// 8.53--5.02
// 58.15--16.28

#include <bits/stdc++.h>
using namespace std;
// 能否通过分段得到所有的盛水区域? 可以
// 如何分段? 
//      通过差分数组,找到每次最后一个正数,加入map
// 分段后如何得到一个段内的盛水数量?
//      找到这个区间内的最小数,和区间两侧的最小值
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>> s;
        s.push(make_pair(height[0],1));
        int index=1,ret=0;
        int stackBtm=height[0];
        for(;index<height.size();index++)
        {
            if(height[index]<s.top().first)
                s.push(make_pair(height[index],1));
            else
            {
                //一撸到底
                int second=1;
                if(stackBtm<=height[index])
                {
                    int h=stackBtm;
                    while(s.size()!=1)
                    {
                        ret+=(h-s.top().first)*s.top().second;
                        s.pop();
                    }
                    s.pop();
                    stackBtm=height[index];
                    s.push(make_pair(height[index],1));
                }
                else // 中间会遇到阻碍停指
                {
                    int h=height[index];
                    while(s.top().first<=height[index])
                    {
                        ret+=(h-s.top().first)*s.top().second;
                        second+=s.top().second;
                        s.pop();
                    }
                    s.push(make_pair(height[index],second));
                }
            }
        }
        return ret;
    }
};
// @lc code=end

