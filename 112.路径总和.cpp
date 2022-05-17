/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 进行分枝定界?
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr)
        {
            if(root->val==targetSum) return true;
        }
        bool l=hasPathSum(root->left,targetSum-root->val);
        bool r=hasPathSum(root->right,targetSum-root->val);
        return l | r;
    }
};
// @lc code=end

