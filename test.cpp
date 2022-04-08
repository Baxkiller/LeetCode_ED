#include <bits/stdc++.h>
using namespace std;

void print(int n[10][10])
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<n[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    // 对于memset的测试
    int nums[10][10];
    print(nums);

    for(int i=0;i<10;i++)
        memset(nums[i],0,sizeof(nums[i]));
        
    print(nums);
}