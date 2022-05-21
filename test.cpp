#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> test;
    for(int i=0;i<10;i++)
        test.insert(i+rand()%10);
    for(auto &it:test)
        cout<<it<<" ";
    cout<<endl;
    test.erase(13);
    
    for(auto &it:test)
    cout<<it<<" ";
    cout<<endl;
}