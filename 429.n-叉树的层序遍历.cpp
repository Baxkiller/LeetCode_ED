/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <bits/stdc++.h>
#include "N_Node.h"
using namespace std;

// 79.75--72.34

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        queue<Node*> curLevel;

        // 特判
        if(root==nullptr) return ret;

        curLevel.push(root);
        while(!curLevel.empty())
        {
            int size=curLevel.size();
            vector<int> levelNums;
            Node* cur;

            for(int i=0;i<size;i++)
            {// 对当前的每个节点进行操作
                cur=curLevel.front();
                curLevel.pop();
                
                // 合法性检查
                if(cur==nullptr) continue;

                // 数值的获取
                levelNums.push_back(cur->val);
                for(auto &it:cur->children)
                    curLevel.push(it);
            }

            // 该层数值的存储
            ret.push_back(levelNums);
        }

        return ret;
    }
};
// @lc code=end

