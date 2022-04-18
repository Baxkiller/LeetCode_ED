/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */
#include <bits/stdc++.h>
using namespace std;
// 18.94
// 更改小思路之后,能够达到80--28

// @lc code=start
bool cmp_value(const pair<string,int> a,const pair<string,int> b)
{
    return a.second<b.second;
}


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // string biaodian="!?',;.";
        // 测试用例简直离谱
        // 需要对输入数据进行处理
        // 保证每个标点符号后面都有空格
        string tmp=paragraph;
        paragraph="";
        for(int i=0;i<tmp.size();i++)
        {
            if(tmp[i]>='a' && tmp[i] <='z')
                paragraph+=tmp[i];
            else if(tmp[i]>='A' && tmp[i] <='Z')
                paragraph+=tmp[i]+('a'-'A');
            else if(tmp[i]==' ')
                paragraph+=' ';
            else // 标点符号
            {
                if(i+1<tmp.size() && tmp[i+1]!=' ')
                    paragraph+=' ';
            }
        }

        stringstream ss;
        ss<<paragraph;
        // 用unordered_map进行存储
        unordered_map<string,int> cnt;

        // 于其对每个单词都检查是不是在禁用列表中
        // 不如先直接进行添加
        // 添加完成后对禁用列表中的单词再减去一个大的数值
        while(getline(ss,paragraph,' '))
        {
            cnt[paragraph]++;
        }
        // 保证禁用单词计数为负数
        for(auto &it:banned)
            cnt[it]-=1002;
        return max_element(cnt.begin(),cnt.end(),cmp_value)->first;
    }
};
// @lc code=end

