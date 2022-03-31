#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
// 给我人看傻了  直接调用C++中的next_permutation库函数即可完成

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
            return;
        // else// 如果不存在下一个排列
        //     reverse(nums.begin(),nums.end());
    }
};
// @lc code=end

