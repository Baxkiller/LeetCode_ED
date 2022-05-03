#include <bits/stdc++.h>
using namespace std;



vector<int>* pointer;
void check(vector<int>& nums)
{
    pointer=&nums;
    if(pointer->size()>1)
    {
        for(int i=0;i<pointer->size();i++)
            cout<<pointer->data()[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    // 尝试getline
    stringstream ss;
    string a="abc aaa";
    ss<<a;
    string tmp;
    getline(ss,tmp,' ');
    getline(ss,a,' ');
    cout<<tmp<<"***"<<a<<endl;
}