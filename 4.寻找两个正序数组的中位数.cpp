#include <bits/stdc++.h>
using namespace std;

// 解题思路:本来想先来一发暴力试一试卡的点
// 结果没想到以下竟然过了
// 暴力的算法比较简单:
// 首先将两个vector合并
// 然后调用sort函数
// 然后将结果输出即可
// 但是这种情况下的时间复杂度比较高,能够到达O((m+n)log(m+n))
// 如果利用好了数组有序这个条件,时间复杂度会改进到O(m+n)
/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        if(nums1.size()&1)
            return nums1[nums1.size()/2];
        else
        {
            int pos=nums1.size()/2;
            return double(nums1[pos]+nums1[pos-1])/2.0;
        }
    }
};
// @lc code=end

