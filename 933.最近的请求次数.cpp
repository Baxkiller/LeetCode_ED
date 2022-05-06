/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class RecentCounter {
public:
    RecentCounter() {
        while(!cnt.empty())
            cnt.pop();
    }
    
    int ping(int t) {
        while(!cnt.empty() && cnt.front()<t-3000)
            cnt.pop();
        cnt.push(t);
        return cnt.size();
    }
    queue<int> cnt;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

