#include <bits/stdc++.h>
using namespace std;


//  初始题解
// map<string,int> breakPoint;

// pair<int,int> getSep(int num,int beichu)
// {
//     int chushu=beichu;
//     if(num<beichu)
//         return make_pair(0,0);
//     return make_pair(num/chushu,num%chushu);
// }

// string IntToString(int num)
// {
//     return to_string(num);
// }

// int toInterger(string number)
// {
//     int ret=0;
//     for(auto it:number)
//     {
//         ret*=10;
//         ret+=it-'0';
//     }
//     return ret;
// }

// int findKthNumber(int n, int k) {
//     int beichu=10;
//     int limit=n>9?9:n;
//     for(int i=1;i<=limit;i++)
//         breakPoint.emplace(IntToString(i),1);
//     while (true)
//     {
//         pair<int,int> bk=getSep(n,beichu);
//         // cout<<bk.first<<" "<<bk.second<<endl;
//         if(bk.first==0)
//             break;
//         for(int i=1;i<bk.first;i++)
//         {
//             breakPoint.emplace(IntToString(i*beichu),beichu);
//         }
//         breakPoint.emplace(IntToString(bk.first*beichu),bk.second+1);
//         beichu*=10;
//         // cout<<beichu<<endl;
//     }
//     int res=0,tmp=0;
//     for(auto it:breakPoint)
//     {
//         if(it.second+tmp>=k)
//         {
//             res=toInterger(it.first)+(k-tmp)-1;
//             break;
//         }
//         else
//             tmp+=it.second;
//     }
//     return res;
// }
/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};
// @lc code=end

