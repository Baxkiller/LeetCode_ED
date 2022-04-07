#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
// 70--57
// 46-- 19
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 经典双指针问题
        int l=0,r=numbers.size()-1;
        vector<int> ret(2);
        while(l<r)
        {
            if(numbers[l]+numbers[r]>target)
                r--;
            else if(numbers[l]+numbers[r]<target)
                l++;
            else
            {
                ret[0]=l+1;
                ret[1]=r+1;
                return ret;
            }
        }
        return ret;
    }
};
// @lc code=end

