/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <bits/stdc++.h>
using namespace std;
// 100--77.86
// 利用双指针进行排序
// 利用已知信息:
//          只包含三种颜色
//          顺序应该是0,1,2
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 用一个指针指向2,另外一个指针指向0或者1
        int l=0,r=nums.size()-1;
        // 先找到做左边的2的位置和最右边的0或者1的位置
        while(l<nums.size() && nums[l]!=2) l++;
        while(r>=0 && nums[r]==2) r--;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            while(l<nums.size() && nums[l]!=2) l++;
            while(r>=0 && nums[r]==2) r--;
        }
        // 此时需要判断是否已经完成置换了
        // 还有1和0的位置是混乱的
        // l指向左边的1,r指向右边的0
        r=l,l=0;
        r--;
        while(l<nums.size() && nums[l]==0) l++;
        while(r>=0 && nums[r]==1) r--;
        while(l<r)
        {
            swap(nums[l],nums[r]);
            while(l<nums.size() && nums[l]==0) l++;
            while(r>=0 && nums[r]==1) r--;  
        }
    }
};
// @lc code=end

