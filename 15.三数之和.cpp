#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// [-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
// [0,-1,1,0,0]
// [-2,-4,-5,-5,-2,-3,-5,-4,-2]
// [1,2,3,4,5]
// [-1,-2,-3,2,-1]

// [6,-5,-6,-1,-2,8,-1,4,-10,-8,-10,-2,-4,-1,-8,-2,8,9,-5,-2,-8,-9,-3,-5]


// @lc code=start

bool checkEqual(const vector<int> &v,const vector<int> &u)
{
    return v[0]==u[0] && v[1]==u[1] && v[2]==u[2];
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;
        if(nums.size()<3) return v;
        if(nums.size()==3)
        {
            if(nums[0]+nums[1]+nums[2]==0)
            {
                v.push_back(nums);
                return v;
            }
            else
                return v;
        }

        sort(nums.begin(),nums.end());
        int FirstPositive,leftLimit,rightLimit;
        for(FirstPositive=0;FirstPositive<nums.size() && nums[FirstPositive]<0;FirstPositive++);
        // 找到第一个等于0或者大于0的数字的位置.
        // if(nums[FirstPositive]==0)
        //     leftLimit=FirstPositive,rightLimit=FirstPositive;
        // else // 位置上为正数,没有0元素存在
        //     leftLimit=FirstPositive-1,rightLimit=FirstPositive;
        leftLimit=FirstPositive,rightLimit=FirstPositive;
        if(leftLimit==-1)
        {
            if(nums[0]==nums[1]==nums[2]==0)
            {
                vector<int> t;
                t.push_back(0);
                t.push_back(0);
                t.push_back(0);
                v.push_back(t);
                return v;
            }
            else
                return v;
        }

        cout<<FirstPositive<<" "<<rightLimit<<endl;

        if(FirstPositive==nums.size())
            return v;
        if(rightLimit==nums.size()) rightLimit--;


        int left=0,right=nums.size()-1,middle=1;

        for(left=0;left<=leftLimit;left++)
        {
            if(left>0 && nums[left]==nums[left-1])
                continue;
            for(right=nums.size()-1;right>=rightLimit;right--)
            {
                if(right<nums.size()-1 && nums[right]==nums[right+1])
                    continue;

                if(right==left) continue;
                
                int target=-nums[left]-nums[right];
                for(int mid=left+1;mid<right;mid++)
                {
                    if(nums[mid]==target)
                    {
                        vector<int> t(3);
                        t[0]=nums[left],t[1]=nums[mid],t[2]=nums[right];
                        v.push_back(t);
                    }
                    else if(nums[mid]>target) 
                    {
                        printf("Left:%d,Mid:%d,Right:%d\n",nums[left],nums[mid],nums[right]);
                        break;
                    }
                }
            }
        }

        auto it=unique(v.begin(),v.end(),checkEqual);
        vector<vector<int>> ret(v.begin(),it);
        return ret;
    }
};
// @lc code=end

