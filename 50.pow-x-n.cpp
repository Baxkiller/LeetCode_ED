/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        // 特数情况处理
        if(x==double(1.0)) return 1.0;
        if(N==0) return 1.0;
        if(N==1) return x;

        double ret=1;
        bool flag=false;
        if(N<0)
        {
            flag=true;
            N=-N;
        }
        while(N)
        {
            if(N&1) ret*=x;
            x*=x;
            N>>=1;
        }
        if(flag) return 1/ret;
        else return ret;
    }
};
// @lc code=end

