#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(2);
    cout<<find(test.begin(),test.end(),2)-test.begin()<<endl;
}