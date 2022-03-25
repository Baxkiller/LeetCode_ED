#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */
// 考虑过程
// 尾数是2和5
// 尾数是5和10
//int countTen=0,countFive=0;
// int tmp=n;
// countTen=tmp/10;
// countFive=countTen;
// if(n-countTen*10>=5) countFive++;
// int cnt=0;
// tmp=5;
// while(tmp*5<=n)
// {
//     cnt++;
//     tmp*=5;
// }
// countFive+=(cnt)*(cnt+1)/2;

// return countTen+countFive;

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        vector<int> TobeCheck;
        int cnt=0;
        for(int i=1;i*5<=n;i++)
        {
            cnt++;
            int tmp=i;
            while(tmp && tmp%5==0) cnt++,tmp/=5;
        }
        return cnt;
    }
};
// @lc code=end

