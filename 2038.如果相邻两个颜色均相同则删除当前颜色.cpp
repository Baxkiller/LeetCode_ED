#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */
    // 初始题解 暴力求解 超时
    // 改进:通过一次遍历 查看连续三个A和连续三个B的个数
    // 当且仅当countA严格大于countB时返回true
    // 时间复杂度O(n)
    // int check(string cs,bool Alice)
    // {
    //     string target;
    //     if(Alice)
    //         target="AAA";
    //     else
    //         target="BBB"; 
    //     int pos=cs.find(target);
    //     cout<<pos<<endl;
    //     return pos;
    // }

    // bool winnerOfGame(string colors) {
    //     int len=colors.length();
    //     while (true)
    //     {
    //         // Alice find the position
    //         int pos=check(colors,1);
    //         if(pos<0)
    //             return false;
    //         else
    //             colors.erase(pos+1,1);
            
    //         pos=check(colors,0);
    //         if(pos<0)
    //             return true;
    //         else
    //             colors.erase(pos+1,1);
    //         /* code */
    //     }
    // }

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int countA=0,countB=0;
        for(int i=2;i<colors.length();i++)
        {
            if(colors[i-2]==colors[i-1] && colors[i-1]==colors[i])
            {
                if(colors[i]=='A') countA++;
                else countB++;
            }
        }
        if(countA>countB)   return true;
        else return false;
    }
};
// @lc code=end

