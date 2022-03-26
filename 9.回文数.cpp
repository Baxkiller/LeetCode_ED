#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string num=to_string(x);
        for(int i=0,j=num.length()-1;i<j;i++,j--)
            if(num[i]!=num[j])
                return false;

        return true;
    }
};
// @lc code=end

