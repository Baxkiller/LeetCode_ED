#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// 可以猜测,本实验中最常用到的操作应当是查询操作
// 最高投票题解
// int lengthOfLongestSubstring(string s) {
//         vector<int> dict(256, -1);   // 用来记录所有字符出现的位置
//         int maxLen = 0, start = -1;  // start代表重复字符的开始位置
//         for (int i = 0; i != s.length(); i++) {
//             if (dict[s[i]] > start)  // 如果第一次遇到该字符,按照上面规则,条件不成立
                                        // 如果第二次遇到该字符,必然成立
                                        // 因为此时是第二次遇到,说明这个字符与前面存在重复,将开始游标start设置为这个字符上一次出现的位置
//                 start = dict[s[i]];
//             dict[s[i]] = i;          // 将该字符的位置赋给dict字符位置
//             maxLen = max(maxLen, i - start); // 每次都要取一次最长
//         }
//         return maxLen;
//     }


// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1)
            return 1;
        int len=0,index=0;
        string res="";
        for(int l=0,r=0;r<s.length();r++)
        {
            int search=0;
            if((search=res.find(s[r]))==-1)
                res+=s[r];
            else
            {
                len=max<int>(res.length(),len);
                res=res.substr(search+1);
                res+=s[r];
                // cout<<res<<endl;
                l=search+1;
            }
        }
        len=max<int>(len,res.length());
        return len;
    }
};
// @lc code=end

