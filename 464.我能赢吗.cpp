/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_map<int,bool> record;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1+maxChoosableInteger)*(maxChoosableInteger)/2 < desiredTotal) return false;
        return dfs(maxChoosableInteger,0,desiredTotal,0);
    }
    bool dfs(int maxLimit,int usedNumbers,int desiredTotal,int currentTotal)
    {
        if(!record.count(usedNumbers))
        {// 如果当前状态没有出现过
            bool res=false;
            for(int i=0;i<maxLimit;i++)
            {// 遍历选择
                if(((usedNumbers>>i)&1)==0)
                {// 说明最后一位是0  也就是还没有使用过
                    if(i+1+currentTotal>=desiredTotal)
                    {// 如果选择了这个数字,超过了目标值
                        res=true;
                        break;
                    }// 如果没有超过目标值
                    if(!dfs(maxLimit,usedNumbers|(1<<i),desiredTotal,currentTotal+i+1))
                    {// 后手选择  发现自己输了  那么我此时就赢了
                        res=true;
                        break;
                    }
                }
            }
            record[usedNumbers]=res;
        }
        // 如果出现过了当前状态  直接返回结果
        return record[usedNumbers];
    }
};
// @lc code=end

