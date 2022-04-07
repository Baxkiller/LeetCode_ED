#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
// 时间复杂度O(1)
// [-1,-100,3,99]\n2
// [1,2,3,4,5,6,7,8]\n5
// 新建数组进行求解:75--29
/*
        int n=nums.size();
        k=k%n;
        if(k==0) return;
        vector<int> ret(nums);
        for(int i=0;i<nums.size();i++)
        {
            nums[(i+k)%n]=ret[i];
        }
*/

// 如何原地进行求解?
// 进行三次reverse 99-47



// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
// @lc code=end

