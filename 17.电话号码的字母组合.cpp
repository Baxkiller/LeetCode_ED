#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:

    vector<string> letters;
    vector<string> ret;
    string digit;
    void getResults(int p,string tmpRes)
    {
        int Index=digit[p]-'2';
        string lts=letters[Index];

        if(p==digit.size()-1)
        {
            for(auto it:lts)
            {
                ret.push_back(tmpRes+it);
            }
            return;
        }

        for(auto &c:lts)
        {
            getResults(p+1,tmpRes+c);
        }
    }

    vector<string> letterCombinations(string digits) {


        if(digits=="") return ret;

        letters.resize(7);
        digit=digits;

        for(int i=0;i<5;i++)
        {
            string tmp="";
            for(int j=0;j<3;j++)
                tmp+=('a'+i*3+j);
            letters[i]=tmp;
        }

        letters[5]="pqrs";
        letters[6]="tuv";
        letters[7]="wxyz";

        getResults(0,"");
        return ret;
    }
};
// @lc code=end

