/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// 单调栈的思想执行
// 要找的是从左到右的单调递减栈,栈顶元素逐渐增大才对
#include <bits/stdc++.h>
using namespace std;
// 时间复杂度应该是O(n),但是运行时间来看只超过了17.75
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int m=heights.size();
        if(m==1) return heights[0];
        // 单调栈
        stack<int> s;
        // 记录左侧点
        vector<int> left(m,-1);
        left[0]=-1;
        // 记录右侧下标
        vector<int> right(m,-1);
        right[m-1]=m;
        s.push(0);
        for(int i=1;i<m;i++)
        {
            // 小于等于就push进去
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                // 也就是说 s.top向右小于它的下标为i
                right[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            right[s.top()]=m;
            s.pop();
        }

        // 处理左边界
        // 此时仍然使用单调递减栈
        s.push(m-1);
        for(int i=m-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                left[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
        {
            left[s.top()]=-1;
            s.pop();
        }

        // 根据左侧和右侧的边界进行求解
        int ret=0;
        for(int i=0;i<m;i++)
        {
            ret=max(ret,heights[i]*(right[i]-left[i]-1));
        }
        return ret;

    }
};
// @lc code=end

