#include <bits/stdc++.h>
using namespace std;

//T03
map<int,int> cnt;
int findRepeatNumber_0(vector<int>& nums) {
    for(auto &it:nums)
    {
        cnt[it]++;
        if(cnt[it]>1) return it;
    }
    return -1;
}

//T21
stack<int> simu;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
    int index=0;
    for(int i=0;i<pushed.size();i++)
    {
        simu.push(pushed[i]);
        while(!simu.empty() && (simu.top()==popped[index]))
        {
            simu.pop();
            index++;
        }
    }
    while(!simu.empty() && simu.top() == popped[index])
    {
        simu.pop();
        index++;
    }
    return index==pushed.size();
}

// 剑指offer T32-1
/*
    3
   / \
  9  20
    /  \
   15   7
*/
// vector<int> levelOrder(TreeNode* root) 
// {
//     queue<TreeNode*> temp;
//     temp.push(root);
//     vector<int> res;
//     while(!temp.empty())
//     {
//         TreeNode* c=temp.front();
//         temp.pop();
//         if(c==NULL) continue;
//         res.push_back(c->val);
//         temp.push(c->left);
//         temp.push(c->right);
//     }
//     return res;
// }

// T33
int search0(vector<int>& nums, int target) {
    auto res=find(nums.begin(),nums.end(),target);
    if(res==nums.end()) return -1;
    else return res-nums.begin();
}

bool ordered(int index,vector<int>& nums)
{
    if(index==0)
        return nums[1]>nums[index];
    else if(index==nums.size())
        return nums[index-1]<nums[index];
    else
        return (nums[index-1]<nums[index]) && (nums[index+1]>nums[index]);
}
// WA
int search1(vector<int>& nums, int target)
{
    int n=nums.size();
    int left=0,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(ordered(mid,nums))
        {
            if(nums[mid]<target) left=mid+1;
            else if(nums[mid]>target) right=mid-1;
            else return mid;
        }
        else
        {
            if(nums[mid]==target) return mid;
            if(nums[0]==target) return 0;
            if(nums.back()==target) return n-1;

            if(nums[mid]>target && nums[0]<target)
                left=0,right=mid;
            else
                left=mid+1,right=n-2;
        }
    }
    return -1;
}

//二分查找  用于有序部分的查找
int binary(int left,int right,vector<int>& nums,int target)
{
    while(left<right)
    {
        int mid=(left+right)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) left=mid+1;
        else right=mid-1;
    }
    if(nums[left]==target) return left;
    return -1;
}
// [3,1]  1
int search(vector<int>& nums,int target)
{
    int n=nums.size();
    int left=0,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(nums[mid]>=nums[left])
        {
            int tempRes=binary(left,mid,nums,target);
            if(tempRes!=-1) return tempRes;
            left=mid+1;
        }
        else
        {
            int tempRes=binary(mid,right,nums,target);
            if(tempRes!=-1) return tempRes;
            right=mid-1;
        }
    }
    if(nums[left]==target) return left;
    return -1;
}

//T1005
int sums(vector<int>& nums)
{
    int res=0;
    for(auto &it:nums) res+=it;
    return res;
}

int largestSumAfterKNegations(vector<int>& nums, int k) 
{
    sort(nums.begin(),nums.end());
    int i=0;
    while(i<nums.size() && nums[i]<0 && k>0)
    {
        nums[i]=-nums[i];
        i++;
        k--;
    }
    if(k%2!=0)
    {
        sort(nums.begin(),nums.end());
        nums[0]=-nums[0];
    } 
    return sums(nums);
}

// T506
vector<string> ret;
vector<string> findRelativeRanks(vector<int>& score) 
{
    ret.resize(score.size());
    map<int,int> range;
    int i=0;
    for(auto &it:score) range.emplace(it,i++);
    i=0;
    for(auto it=range.rbegin();it!=range.rend();it++)
    {
        if(i==0) ret[it->second]="Gold Medal";
        else if(i==1) ret[it->second]="Silver Medal";
        else if(i==2) ret[it->second]="Bronze Medal";
        else ret[it->second]=to_string(i+1);
        i++;
    }
    return ret;
}

//T74
bool searchMatrix0(vector<vector<int>>& matrix, int target) 
{
	if(matrix.empty()) return false;
    int m=matrix.size(),n=matrix.front().size();
    // m行,n列
    int left=0,right=m-1;
    cout<<m<<" "<<n<<endl;
    int index=0;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(matrix[mid][0]<target) 
	   {
		   if(matrix[mid].back()>=target) index=mid,break;
		   else left=mid+1;

	   }
        else if(matrix[mid][0]>target) right=mid-1;
        else return true;
    }
    if(index==0)
    {
		index=min(left,right);
		index=max(0,index);
    }
    left=0,right=n-1;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(matrix[index][mid]<target) left=mid+1;
        else if(matrix[index][mid]>target) right=mid-1;
        else return true;
    }
    if((left<=n-1 && matrix[index][left]==target) || (right>=0 && matrix[index][right]==target)) return true;
    else return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	for(auto line:matrix)
	{
		for(auto i:line)
		{
			if(i==target) return true;
			else if(i>target) return false;
		}
	}
	return false;
}

int findMin(vector<int>& nums) {
	int n=nums.size();
	int left=0,right=n-1;
	while(left<right)
	{
		int mid=(left+right)/2;
		if(nums[mid]<nums[right]) right=mid-1;
		else if(nums[mid]>nums[right]) left=mid+1;
		else if(nums[mid]==nums[right]) break;
	}
	return nums[right];
}


int main()
{
    vector<vector<int>> nums;
    vector<int> t;
    t.push_back(1);
    t.push_back(1);
    nums.push_back(t);
    int target=0;
    cout<<searchMatrix(nums,target)<<endl;
}