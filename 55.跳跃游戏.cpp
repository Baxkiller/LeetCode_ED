/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <bits/stdc++.h>
using namespace std;
// 使用普通方法时间复杂度O(n),11.78
// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>maxIndex) return false;
            maxIndex=max(maxIndex,i+nums[i]);
            if(maxIndex>=nums.size()-1) return true;
        }
        printf("Error!\n");
        return true;
    }
};
// @lc code=end

