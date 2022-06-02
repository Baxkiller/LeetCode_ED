/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include  <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty())
        {
            vector<int> level;
            cnt=q.size();
            while(cnt--)
            {
                TreeNode* fnt=q.front();
                q.pop();
                level.push_back(fnt->val);
                if(fnt->left!=nullptr) q.push(fnt->left);
                if(fnt->right!=nullptr) q.push(fnt->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};
// @lc code=end

