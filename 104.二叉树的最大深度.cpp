/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <bits/stdc++.h>
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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        // 不适用递归方法进行求解
        queue<TreeNode*> q;
        q.push(root);
        int ret=0;
        while(!q.empty())
        {
            int cnt=q.size();
            while(cnt--)
            {
                TreeNode* fnt=q.front();
                q.pop();
                if(fnt->left!=nullptr) q.push(fnt->left);
                if(fnt->right!=nullptr) q.push(fnt->right);
            }
            ret++;
        }
        return ret;
    }
};
// @lc code=end

