#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// 暴力求解 超时
// 双指针也太巧妙了!!
// 也就是尝试去消隐状态,将必然会导致结果减小的状态消除,只计算可能会使结果增大的状态.

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        //第一发必然是暴力求解
        int left=0,right=height.size()-1,ret=0;
        while(left<right)
        {
            ret=height[left]<height[right]?
                max((right-left)*height[left++],ret):
                max((right-left)*height[right--],ret);
        }

        return ret;
    }
};
// @lc code=end

