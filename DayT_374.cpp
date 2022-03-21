#include <bits/stdc++.h>
using namespace std;
int n;
int guess(int i);

int solution()
{
    long long l=1,r=n;
    while(l<r)
    {
        long long mid=(l+r)/2;
        if(guess(mid)==-1) l=mid-1;
        else if(guess(mid)==1) r=mid+1;
        else return mid;
    }
    return l;
}

int main()
{
    cout<<"test"<<endl;
}