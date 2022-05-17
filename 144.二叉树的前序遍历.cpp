/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

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
    vector<int> ret;
    void preOrder(TreeNode* r)
    {
        if(r==nullptr) return;
        ret.push_back(r->val);
        preOrder(r->left);
        preOrder(r->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return ret;
    }
};
// @lc code=end

