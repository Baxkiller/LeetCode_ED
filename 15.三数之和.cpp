#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// 初始思路: 暴力情况下需要进行三层的遍历,为了缩小遍历的次数
// 我尝试将外面两层遍历的范围尽量进行缩小
// 考虑到如果想要三个数的和为0,那么除去三个全部为0的情况外
// 必然其中有一个数字是小于0的,有一个数字是大于0的,剩下的数字需要进行查询,因此
// 通过规定外层两次循环的范围,尝试进行求解,但是卡在第315个点
// 也就是说,上述优化方法是行不通的,
// 因为尽管我缩小了遍历的范围,但是总体上,时间复杂度仍然达到了O(n^3)
/* 
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
            if(mid>left+1 && nums[mid]==nums[mid-1]) continue;

            if(nums[mid]==target)
            {
                vector<int> t(3);
                t[0]=nums[left],t[1]=nums[mid],t[2]=nums[right];
                v.push_back(t);
            }
            else if(nums[mid]>target) 
            {
                // printf("Left:%d,Mid:%d,Right:%d\n",nums[left],nums[mid],nums[right]);
                break;
            }
        }
    }
}

// auto it=unique(v.begin(),v.end(),checkEqual);
// vector<vector<int>> ret(v.begin(),it);
// return ret;

return v;
*/

// 双指针的求解方法?
// 实际上是在原本的双指针的基础上叠一层循环,也就是对于一个数字nums[i],固定其位置
// 然后设置双指针,分别进行判断
// 此时的时间复杂度为O(n^2)=i的遍历以及双指针的一次遍历

/*

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
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int left,right;
        int i=0;
        vector<vector<int>> v;
        if(nums.size()<3) return v;

        if(nums.size()==3)
        {
            int sums=0;
            for(auto &it:nums) sums+=it;
            if(sums==0) v.push_back(nums);// 仅有的三个数和为0
            return v;
        }

        sort(nums.begin(),nums.end());
        if(nums[0]>0) return v;

        vector<int> tmpRes(3);

        for(i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int target=-nums[i];
            left=i+1,right=nums.size()-1;

            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    tmpRes[0]=nums[i];
                    tmpRes[1]=nums[left];
                    tmpRes[2]=nums[right];
                    v.push_back(tmpRes);
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;

                    // 因为忘记这一步而进入死循环
                    // 因为当两者相加的和为目标值之后,l和r必然不会再次出现在当前的答案中
                    left++,right--;
                }
                else if(nums[left]+nums[right]>target)
                {
                    right--;
                }
                else
                    left++;
            }

        }
        return v;
    }
};
// @lc code=end

