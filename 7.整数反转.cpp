#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
// 很简单 直接求解就好了

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool minus=x<0;
        x=abs(x);
        long long ret=0;
        while(x)
        {
            ret*=10;
            ret+=x%10;
            x/=10;
        }
        if(minus) ret=-ret;
        if(ret>INT32_MIN && ret<INT32_MAX)
            return ret;
        else
            return 0;
    }
};
// @lc code=end

