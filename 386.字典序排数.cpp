/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */
#include <bits/stdc++.h>
using namespace std;

// 如何处理字典序?
// map可以使用字典序
// 或者将数字转换为string类型的数字
// 然后使用sort函数进行排序
// 72--24
// 100--14.93
// @lc code=start
class Solution {
public:
    vector<int> ret;
    int limit;
    void recursion(int num)
    {
        if(num>limit) return;
        ret.push_back(num);
        num*=10;
        for(int i=0;i<10 && num+i<=limit ;i++)
        {
            recursion(num+i);
        }
        return;
    }

    vector<int> lexicalOrder(int n) {
        // 根据尝试
        // 发现 大体存在以下的规律
        // 1-10-100-1000-...
        // 1-11-110-1100-...
        // 1-12-120-...
        // 也就相当于在给定一个数字后,先乘以10,然后从0开始再到9进行递归

        this->limit=n;
        for(int i=1;i<10;i++)
            recursion(i);
        return ret;
    }
};
// @lc code=end

