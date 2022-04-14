/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
// 使用散列表成功a
// 32.62--98.95
#include <bits/stdc++.h>
using namespace std;
// 最多2*1e5个数值插入
// 可以想到的是使用散列表进行映射
// 但是如果是散列表,如何保证随机获取的数字概率相同呢
// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        m.emplace(val,1);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) return false;
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int r=rand()%m.size();
        auto it=m.begin();
        for(;r>0;r--)
            it++;
        return it->first;
    }

private:
    unordered_map<int,int> m;
    int currentKey;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

