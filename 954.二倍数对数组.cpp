#include <bits/stdc++.h>
using namespace std;

/*效果稀烂
// 24.73--58.05
// 特判
        if(arr.size()==0)
            return true;

        // 存储数字的值和对应数字的个数
        map<int,int> nums;
        for(auto &it:arr)
        {
            if(nums.find(it)==nums.end())
                nums[it]=0;
            nums[it]++;
        }
        
        for(auto it:nums)
        {
            if(it.second==0) continue;
            if(it.second<0) return false;

            if(it.first<0)
            {
                if(it.first&1) return false;
                if(nums.find(it.first/2)!=nums.end())
                {
                    nums[it.first/2]-=it.second;
                }
                else //equals zero
                {
                    cout<<it.first<<endl;
                    return false;
                }
            }
            else
            {
                if(nums.find(it.first*2)!=nums.end())
                    nums[it.first*2]-=it.second;
                else
                {
                    cout<<it.first*2<<" "<<nums[it.first*2]<<endl;
                    return false;
                }
            }
        }
        return true;
*/

/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */
// [2,1,2,1,1,1,2,2]
// [-5,-2]
// [-5,-3]

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {

        if(arr.empty()) return true;

        map<int,int> nums;
        for(auto &it:arr)
            nums[it]++;

        auto it=nums.begin();
        int key=0,value=0;
        for(;it!=nums.end();)
        {
            key=it->first;
            value=it->second;
            if(value<0) return false;
            if(value==0) continue;
            it++;
            if(key<0)
            {
                // if(it->first&1) return false;
                if(it->first*2!=key) return false;
                else{
                     it->second-=value;
                     if(it->second==0) it++;
                     else if(it->second<0) return false;
                }
            }
            else if(key>0)
            {
                if(it->first!=key*2) return false;
                else{
                    it->second-=value;
                    if(it->second==0) it++;
                    else if(it->second<0) return false;
                }
            }
            else
            {
                if(value&1) return false;
            }
        }


        return true;
    }
};
// @lc code=end