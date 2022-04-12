/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */
#include <bits/stdc++.h>
using namespace std;
/*

    long long C(int sub,int sup)
    {
        if(sup>sub) return 0;
        if(sup==sub || sup==0) return 1;
        long long ret=A(sub,sub)/(A(sub-sup,sub-sup)*A(sup,sup));
        return ret;
    }
    long long A(int sub,int sup)
    {
        if(sup<=0) return 1;
        long long ret=1;
        for(int i=sub;i>sub-sup;i--)
            ret*=i;
        return ret;
    }
    long long toMinus(int n)
    {
        if(n==1) return 0;
        long long cntToMinus=0;
        // 实际上是一个数学问题
        for(int i=2;i<=n;i++)
        {// i代表相同数字的个数
            // 如果相同数字不包含最前面的数字的话
            cntToMinus+=C((n-1),i)*C(9,1)*C(9,1)*A(8,n-i-1);
            // 如果相同数字包含最前面的数字的话
            cntToMinus+=C(n-1,i-1)*C(9,1)*A(9,n-i);
            cout<<n<<" : "<<cntToMinus<<endl;
            // 还要包括当前的最高位为0的情况
            // cout<<cntToMinus<<endl;
        }
        cntToMinus+=toMinus(n-1);
        return cntToMinus;
    }

*/
// @lc code=start
class Solution {
public:
    long long A(int sub,int sup)
    {
        if(sup<=0) return 1;
        long long ret=1;
        for(int i=sub;i>sub-sup;i--)
            ret*=i;
        return ret;
    }

    int countNumbersWithUniqueDigits(int n) {
        // 总数为1en个数字
        // 先找出有相同数字的个数,然后总数-具有相同数字的个数
        // 实际上只需要找具有n位相同的数字个数
        long long ret=0;
        if(n==0) return 1;
        if(n==1) return 10;

        ret+=9*A(9,n-1);
        return ret+countNumbersWithUniqueDigits(n-1);
    }
};
// @lc code=end

