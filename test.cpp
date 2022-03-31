#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> revector;
    for(int i=0;i<10;i++)
        revector.push_back(i);
    for(int i=0;i<10;i++)
        cout<<revector[i]<<" ";
    cout<<endl;

    reverse(revector.begin(),revector.end());
    for(auto it:revector)  
        cout<<it<<" ";
    cout<<endl;

    
}