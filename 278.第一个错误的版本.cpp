/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned long long left=1,right=n;
        unsigned long long mid=0;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(isBadVersion(mid))
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
};
// @lc code=end

