#include <bits/stdc++.h>
using namespace std;

string IntToString(int num)
{
    return to_string(num);
}

int toInterger(string number)
{
    int ret=0;
    for(auto it:number)
    {
        ret*=10;
        ret+=it-'0';
    }
    return ret;
}

int main()
{
    vector<vector<int>> nums(3,vector<int>(3));
    cout<<nums.size()<<" "<<nums[0].size()<<endl;

    vector<vector<int>> tmp(nums);
    cout<<tmp.size()<<" "<<tmp[0].size()<<endl;
    return 0;
}