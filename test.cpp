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
    vector<int> nums;
    int n=10;
    while(n--) nums.push_back(n);

    for_each(nums.begin(),nums.end(),[](auto &i)->void{i=i*3;});
    copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
}