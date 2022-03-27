#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(10,5);
    for(auto &it:nums) cout<<it<<" ";
    cout<<endl;
    
    nums.resize(15,2);
    for(auto &it:nums) cout<<it<<" ";
    cout<<endl;
}