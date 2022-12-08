#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> sorted;
        for(int i=0;i<n;i++)
        {
            sorted.push_back(nums[i]);
            sorted.push_back(nums[n+i]);
        }

        return sorted;
    
    }
};
// @lc code=end

