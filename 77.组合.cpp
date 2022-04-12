/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

//  参数传递方式用哪一种比较好呢/
//  如果使用vector 耗时比较长 12--5
//  如果使用位图来记录是否使用 耗时最快能到98.7
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int k,n;
    vector<vector<int>> ret;
    void recursion(int haveCnt,int index,int record)
    {// 使用位记录要选择哪些数字
        if(haveCnt==k || index>n)
        {
            if(haveCnt==k)
            {
                int index=1;
                vector<int> tmp;
                while(record)
                {
                    if(record & 1) 
                        tmp.push_back(index);
                    record>>=1;
                    index++;
                }
                ret.push_back(tmp);
                tmp.clear();
            }
            return;
        }
        // 添加剪枝
        // 如果剩下的全部都加入也凑不够k个
        // n-index+1  算上现在的这个数字,还剩下的未处理的
        // haveCnt    已经加入的
        if(n-index+1+haveCnt < k)
            return;

        // 不填加当前index 的这个数字
        recursion(haveCnt,index+1,record);
        record |=1<<(index-1);
        recursion(haveCnt+1,index+1,record);
    }
    vector<vector<int>> combine(int n, int k) {
        this->n=n;
        this->k=k;
        recursion(0,1,0);
        return ret;
    }
};
// @lc code=end

