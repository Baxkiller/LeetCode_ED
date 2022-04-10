/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string maps[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int> res;
        string wordMap="";
        for(auto &it:words)
        {
            for(auto &c:it)
                wordMap+=maps[c-'a'];
            res[wordMap]++;
            wordMap="";
        }
        return res.size();
    }
};
// @lc code=end

