/*
 * @lc app=leetcode.cn id=398 lang=cpp
 *
 * [398] 随机数索引
 */
#include <bits/stdc++.h>
using namespace std;
// 使用 无序映射?  
// @lc code=start
class Solution {
    map<int,vector<int>> m;
public:
    Solution(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n= rand()%(m[target].size());
        return m[target][n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end

