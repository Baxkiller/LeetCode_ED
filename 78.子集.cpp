/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <bits/stdc++.h>
using namespace std;
// 首先考虑使用位运算来完成
// 因为nums.length 小于等于10位
// 所以使用一个简单的int就可以表示位信息
// 100--97
// @lc code=start
typedef long long ll;

class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        int record=0;
        ll limit=1 << nums.size();
        limit-=1;
        vector<int> tmp;
        vector<vector<int>> ret;
        for(;record <=limit;record++)
        {
            int index=0;
            int i=record;
            while(i)
            {
                if(i & 1)
                    tmp.push_back(nums[index]);
                index++;
                i>>=1;
            }
            ret.push_back(tmp);
            tmp.clear();
        }
        return ret;
    }
};
// @lc code=end

