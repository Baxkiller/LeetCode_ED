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
    map<string,int> nums;
    nums.emplace(to_string(1),0);
    nums.emplace(to_string(10),0);
    nums.emplace(to_string(11),0);
    nums.emplace(to_string(110),0);
    nums.emplace(to_string(109),0);
    nums.emplace(to_string(2),0);
    for(auto it:nums)
    {
        cout<<it.first<<" ";
    }
    cout<<endl;
}