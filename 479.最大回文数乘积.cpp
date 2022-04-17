/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */
#include <bits/stdc++.h>
using namespace std;
// 根据官方题解,通过枚举进行求解
// 也就是尝试通过枚举回文数的左半部分,从大到小进行枚举,知道找到这个数字为止
// 枚举之后要判断是否可以通过两个n位的数字相乘得到这个数字
// @lc code=start
typedef long long ll;

class Solution {
public:
    int getBitNum(ll num)
    {// 获取数字num的位数
        int ret=0;
        while(num){
            ret++;
            num/=10;
        }
        return ret;
    }
    // 检查回文数能否被整除
    bool CheckNumber(ll num,int n)
    {
        ll limit=sqrt(num);
        ll begin=pow(10,n)-1;
        for(int i=begin;i>=limit;i--)
        {
            if(num%i==0)
            {// 需要检查是否因子是不是都为n位数
                if(getBitNum(num/i)==getBitNum(i) && getBitNum(i)==n)
                    return true;
            }
        }
        return false;
    }

    ll MakeReturnNum(ll left)
    {
        // 给定左半部分,如何生成完整的回文数?
        // 默认是偶数位
        ll tmp=left;
        while(tmp)
        {
           left*=10;
           left+=tmp%10;
           tmp/=10; 
        }
        return left;
    }

    int largestPalindrome(int n) {
        if(n==1) return 9;
        // 由于两个n位数,乘积做多是2n位
        // 那么左侧的位数为n,右侧也是n
        ll Maximum=pow(10,n);
        ll Minimum=pow(10,n-1);
        for(int i=Maximum-1;i>=Minimum;i--)
        {// 进行枚举
            // 如何将当前的左半部分构成完整的回文数?
            if(CheckNumber(MakeReturnNum(i),n))
            {
                return MakeReturnNum(i)%1337;
            } 
        }
        return 0;
    }
};
// @lc code=end

