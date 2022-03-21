#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
int n;

void dfs(vector<int> cur,int index)
{
    if(cur.empty() || index==cur.size())
    {
        sort(cur.begin(),cur.end());
        unique(cur.begin(),cur.end());
        res.push_back(cur);
        return;
    }
    dfs(cur,index+1);
    cur.erase(cur.begin()+index);
    dfs(cur,index);
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    n=nums.size();
    dfs(nums,0);
    return res;
}


// T15
bool unique(const vector<int>& a,const vector<int>& b)
{
    if(a.size()!=b.size()) return false;
    for(int i=0;i<a.size();i++)
        if(a[i]!=b[i]) return false;
    return true;
}

vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> res;
    int i=0,j=0;
    for(;i<nums.size();i++)
    {
        for(;j<i;j++)
        {
            int temp=nums[i]+nums[j];
            temp=-temp;
            auto pos=find(nums.begin(),nums.end(),temp);
            if(pos!=nums.end())
            {
                vector<int> one(3);
                one[0]=(nums[i]);
                one[1]=(nums[i]);
                one[2]=temp;
                sort(one.begin(),one.end());
                res.push_back(one);
            }
        }
    }
    return res;
}