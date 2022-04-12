/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <bits/stdc++.h>
using namespace std;
// 使用next_permutation
// 速度快100-90.68
// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        ret.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ret.push_back(nums);
        return ret;
    }
};
// @lc code=end

