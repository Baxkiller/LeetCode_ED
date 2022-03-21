#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    auto firstp=find(nums.begin(),nums.end(),target);
    auto lastp=find(nums.rbegin(),nums.rend(),target);
    vector<int> res;
    if(firstp==nums.end()){
        nums.push_back(-1);
        nums.push_back(-1);
        return res;
    }
    res.push_back(firstp-nums.begin());
    res.push_back((lastp-nums.rend()));
}


int main()
{

}