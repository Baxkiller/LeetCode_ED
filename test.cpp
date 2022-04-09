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

void PrintS(char* c)
{
    for(int i=0;c[i]!='\0';i++)
        cout<<c[i]<<" ";
    cout<<endl;
}

void test(int* &nums)
{
    nums=nullptr;
    return;
}

int main()
{
    int *nums=new int[10];
    test(nums);
    if(nums==nullptr) cout<<"Y"<<endl;
    else
        for(int i=0;i<10;i++) cout<<nums[i]<<" ";
}