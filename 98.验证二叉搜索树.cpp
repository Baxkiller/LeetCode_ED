/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
// [5,4,6,null,null,3,7]
// [120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]

class Solution {
public:
    bool inOrder(TreeNode* root)
    {
        if(root==nullptr) return true;
        if(!inOrder(root->left)) return false;
        if(root->val <=preVal) return false;
        preVal=root->val;
        return inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        preVal=INT64_MIN;
        return inOrder(root);
    }
private:
    long long preVal;
};
// @lc code=end

