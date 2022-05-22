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
        if(s.empty())
        {
            s.push(val);
            minValue.push(val);
        }
        else
        {
            s.push(val);
            if(val < minValue.top())
                minValue.push(val);
            else
                minValue.push(minValue.top());
        }
    }
    
    void pop() {
        s.pop();
        minValue.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minValue.top();
    }
private:
    stack<int> s;
    stack<int> minValue;
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

