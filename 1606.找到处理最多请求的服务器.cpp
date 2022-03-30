/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
public:

    struct node{
        int finish;
        int id;

        bool operator > (const node& other) const {
            if(finish == other.finish)return id > other.id;
            return finish > other.finish;
        }
    };
    
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        vector<int> cnt(k);
        priority_queue<node,vector<node>,greater<>> working;
        set<int> waiting;
        vector<int> ans;
        int m = 0;
        for(int i = 0;i < k;i++)waiting.insert(i);
        for(int i = 0;i < arrival.size();i++){
            while(working.size() && working.top().finish <= arrival[i]){
                waiting.insert(working.top().id);
                working.pop();
            }
            auto cur = waiting.lower_bound(i % k);
            if(cur == waiting.end())cur = waiting.begin();
            if(cur == waiting.end())continue;
            working.push({arrival[i] + load[i],*cur});
            m = max(m,++cnt[*cur]);
            waiting.erase(cur);
        }
        for(int i = 0;i < k;i++){
            if(cnt[i] == m)ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

