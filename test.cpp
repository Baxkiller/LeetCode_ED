#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums;
    for(int i=0;i<5;i++)
        nums.push_back(i);
    cout<<nums.capacity()<<endl;
    nums.shrink_to_fit();
    cout<<nums.capacity()<<endl;
}