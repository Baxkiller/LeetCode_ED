#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
// 双指针 63.95--9
// 不使用等于判断: 36.19--79
// 将nums.size() 设定变量  87.31--41.9
// 使用等于判断    97.24--21.26

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 既然是双指针,那么就设定一个双指针
        // l指向当前的的位置
        // r指向后面的第一个非零的位置
        int n=nums.size();
        int l=0,r=1;
        while(l<n && nums[l]!=0) l++;
        r=l+1;
        while(r<n && nums[r]==0) r++;

        // 进行交换
        // 结束条件:right==nums.size()
        while(r<n)
        {
            swap(nums[l],nums[r]);
            while(l<n && nums[l]!=0) l++;
            // l恢复第一个为0的数字的位置
            // 同时要让r恢复非0的位置
            while(r<n && nums[r]==0) r++;
        }
        
    }
};
// @lc code=end

