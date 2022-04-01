#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

/*
原题解:
        if(nums.size()==1)
        {
            if(nums[0]==target) return 0;
            else return -1;
        }

        int left=0,right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else
                return mid;
        }
        return -1;
*/
/*STL题解
        // 尝试直接调用stl函数呢
        // lower_bound 第一个不小于的
        auto it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end()) return -1;
        if(*it==target) return it-nums.begin();
        else return -1;
*/

// 使用STL函数:55.4%---19.72%
// 自己来写:   79.32%---98.16%
// 结果不言而喻


// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            if(nums[0]==target) return 0;
            else return -1;
        }

        int left=0,right=nums.size()-1;
        int mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[mid]>target)
                right=mid-1;
            else if(nums[mid]<target)
                left=mid+1;
            else
                return mid;
        }
        return -1;
    }
};
// @lc code=end

