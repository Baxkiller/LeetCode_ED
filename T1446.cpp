#include <bits/stdc++.h>
using namespace std;

map<char,int> cs;
int maxPower(string s) 
{
    int res=0;
    char pre='\0';
    for(auto c:s)
    {
        if(pre!=c)
        {
            res=max(res,cs[pre]);
            cs[pre]=0;
            cs[c]++;
            pre=c;
        }
        else
            cs[c]++;
    }
    res=max(res,cs[res]);
    return res;
}

int main()
{

}