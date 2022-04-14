/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
// 25.53--43.24
// 如何使用更加更加高效的方式进行映射
// 将map更改为unordered_map之后,37.82--81.33 存储效率增加
// 可以使用自定义hash?
// 自定义hash的确定,通过参考大神思路,可以选择使用质数相乘映射来完成
// 保证不同的字母乘上去的结果必然不同!!
// 一定要注意,这里使用的数据类型为double
#include <bits/stdc++.h>
using namespace std;
// ["aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"]

// 如何进行映射?
// @lc code=start
class Solution {
public:
    int m[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    double mapping(string s)
    {// 是否需要将所有的char排序之后返回排序后的结果,可以保证符合条件
    // 但是排序时间为O(NlogN),时间复杂度相对较高
        double ret=1;
        for(auto &c:s)
        {
            ret*=m[c-'a'];
        }
        return ret;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<double,vector<string>> tmp;
        for(auto &s:strs)
        {
            // cout<<s.size()<<"  "<<mapping(s)<<endl;
            tmp[mapping(s)].push_back(s);
        }
        for(auto &it:tmp)
            ret.push_back(it.second);
        return ret;
    }
};
// @lc code=end

