/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        m.insert(val);
    }
    
    void pop() {
        int delVal=s.top();
        s.pop();
        auto it=m.find(delVal);
        m.erase(it);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *m.begin();
    }
private:
    stack<int> s;
    multiset<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

