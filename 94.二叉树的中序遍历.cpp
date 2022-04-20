/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
// 中序遍历=左根右
class Solution {
public:
vector<int> ret;

void recursion(TreeNode *r)
{
    if(r->left!=nullptr)
        recursion(r->left);
    ret.push_back(r->val);
    if(r->right!=nullptr)
        recursion(r->right);
}

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return ret;
        recursion(root);
        return ret;
    }
};
// @lc code=end

