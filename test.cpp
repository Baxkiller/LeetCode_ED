#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int nums[]={2,1,5,6,2,3};// 6个数字
    int record[6];
    s.push(nums[0]);
    // 搞一个单调递减栈出来
    for(int i=0;i<6;i++)
    {
        while(s.top()<nums[i])
        {

        }
    }
}