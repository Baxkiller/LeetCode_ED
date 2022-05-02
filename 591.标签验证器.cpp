/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */
// 正则表达式的使用?
// 
// @lc code=start
class Solution {
public:
    bool isValid(string code) {
        regex r1 = regex("<!\\[CDATA\\[.*?\\]\\]>|t") ;
        regex r2 = regex("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, r1 , "-");
        // cout<<code<<endl;
        string prev = "";
        while(code != prev){
            prev = code;
            code = regex_replace(code, r2, "t");
            cout<<code<<endl;
        }
        return code == "t";
    }
};
// @lc code=end

