#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
// 两个方法:直接排序 63-31
//         双指针与二分查找 83-90

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 作为分界线
        int min_index=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
            if(nums[i]<nums[min_index]) min_index=i;
        }
        vector<int> n(nums.size());
        int index=0;
        // 创建使用双指针进行插入
        int l=min_index,r=min_index+1;
        int rightLimit=nums.size();
        while(l>=0 && r<rightLimit)
        {
            if(nums[l]<nums[r])
            { 
                n[index++]=nums[l];
                l--;
            }
            else
            {
                n[index++]=nums[r];
                r++;
            }
        }
        if(l<0)
        {
            while(r<rightLimit)
                n[index++]=nums[r],r++;
        }
        else
            while(l>=0)
                n[index++]=nums[l],l--;

        return n;
    }
};
// @lc code=end

