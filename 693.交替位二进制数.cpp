#include <bits/stdc++.h>
using namespace std;

// 使用位操作进行移位进行不同位数的判定 可以直接完成
/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool pre=0;
        if(n&1) pre=1;
        else pre=0;
        while(n)
        {
            n>>=1;
            if((n&1)==(pre)) return false;
            pre=n&1;
        }
        return true;
    }
};
// @lc code=end

