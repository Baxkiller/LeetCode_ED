#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5,maxK=448;// sqrt(n*2)
ll preSum[maxn+1];
int n;


void getData()
{
    ll sums=0;
    int tmp=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;sums+=tmp;
        preSum[i]=sums;
    }
    preSum[n]=sums;
}

struct Interval
{
    int l,r,sums;
};
vector<Internal> I[maxK];


int main()
{
    getData();
    // 通过vector存储长度分别为1,2,...的区间的信息,然后搜索所有信息,得到解答案
    int kLimit=sqrt(2*n)+1;
    for(int len=1;len<kLimit;len++)
    {// 给定每个区间的长度
        // 左端点通过计算可以得到
        for(int l=(len-1)*len/2;l+len < n;l++)
        {
            I[len].emplace_back(l,l+len,preSum[l+len+1]-preSum[l]);
        }
    }
    //.... 时间有限,思路为主
}