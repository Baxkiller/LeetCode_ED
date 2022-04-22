/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */
#include <bits/stdc++.h>
using namespace std;

// 首先暴力法就应该是外层k,内层是数组的每个数值
// 但是时间复杂度O(n^2) 
// 但是想要通过这个题,复杂度应该控制在至少O(nlogn)
// 二分求解?
// 应该是尝试剪枝?
// 可以直接查找数学关系  然后做到在O(n)的复杂度内完成
// 83.74
// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& num) {
        vector<long long> nums(num.size());
        nums[0]=num[0];
        long long initSums=0;
        long long perSum=nums[0];
        int n=num.size();
        for(int i=1;i<n;i++)
        {
            nums[i]=num[i];
            perSum+=nums[i];
            initSums+=nums[i]*i;
            // 顺便求取前缀和
            nums[i]+=nums[i-1];
        }

        long long maxRes=initSums;
        long long tempSums=0;
        for(int i=1;i<n;i++)
        {
            tempSums+=perSum;
            long long tmp=nums[i-1]*n;
            maxRes=max(maxRes,initSums-tempSums+tmp);
        }
        return maxRes;

    }
};
// @lc code=end

