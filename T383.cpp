#include <bits/stdc++.h>
using namespace std;


map<char,int> a,b;
bool canConstruct(string ransomNote, string magazine) 
{
    for(auto &it:ransomNote) a[it]++;
    for(auto &it:magazine) b[it]++;
    for(auto it:a)
        if(b[it.first]<it.second) return false;
    return true;
}