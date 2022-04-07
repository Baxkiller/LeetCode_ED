#include <bits/stdc++.h>
using namespace std;

void print(int *n)
{
    for(int i=0;i<20;i++)
        cout<<n[i]<<" ";
    cout<<endl;
}

int main()
{
    // 对于memset的测试
    int nums[20];
    print(nums);
    memset(nums,0,sizeof(nums));
    print(nums);
    return 0;
}