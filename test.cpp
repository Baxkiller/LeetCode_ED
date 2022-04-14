#include <bits/stdc++.h>
using namespace std;

bool is_prime(int num)
{
    for(int i=2;i<=sqrt(num);i++)
        if(num%i==0) return false;
    return true;
}

int main()
{
    int cnt=0;
    for(int i=2;cnt<26;i++)
    {
        if(is_prime(i)){
            cout<<i<<",";
            cnt++;
        }
    }
    cout<<"\nOver!"<<endl;
}