#include <bits/stdc++.h>
using namespace std;

int main()
{
    int **nums=new int*[10];
    for(int i=0;i<10;i++)
        nums[i]=new int[2];
    for(int i=0;i<10;i++)  
        for(int j=0;j<2;j++)
            cout<<nums[i][j]<<" ";
}