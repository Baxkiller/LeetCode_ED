/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
// 100%--78.27%
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 这不就是个数学题么
        // C(m+n-2,n-1)
        // 特判
        if(m==1 || n==1) return 1;

        // 原来难度在于 超出long long 的表示范围
        int sums=n+m-2;
        int small=min(m-1,n-1);
        unsigned long long fenzi=1;
        unsigned long long fenmu=small;
        while(small--)
        {
            fenzi*=sums;
            sums--; 
            if(small)
            {
                if(fenzi%small==0)
                {
                    fenzi/=small;
                }
                else
                    fenmu*=small;
            }
        }
        return fenzi/fenmu;
    }
};
// @lc code=end

