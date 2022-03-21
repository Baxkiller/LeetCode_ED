#include <bits/stdc++.h>
using namespace std;
queue<char> NoRepeat;
map<char,int> inQ;
string s;

void init()
{
    cin>>s;
}

int main()
{
//    init();
    int maxLen=0;
    for(int i=0;i<s.length();i++)
    {
        if(inQ[s[i]]==0)
        {
            NoRepeat.push(s[i]);
            inQ[s[i]]++;
        }
        else
        {
            maxLen=max(maxLen,(int)NoRepeat.size());
            while(NoRepeat.front()!=s[i])
            {
                inQ.erase(NoRepeat.front());
                NoRepeat.pop();
            }
            NoRepeat.pop();
            NoRepeat.push(s[i]);
        }
    }
    maxLen=max(maxLen,(int)NoRepeat.size());
//    cout<<maxLen<<endl;
    return maxLen;
}