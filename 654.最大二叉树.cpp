/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMax(int l,int r,vector<int>& nums)
    {
        if(r==l) return nullptr;
        else if(r==l+1) return new TreeNode(nums[l]);

        int max_ele=max_element(nums.begin()+l,nums.begin()+r)-nums.begin();
        TreeNode* root=new TreeNode(nums[max_ele]);

        if(max_ele==l)
            root->right=constructMax(l+1,r,nums);
        else if(max_ele==r-1)
            root->left=constructMax(l,r-1,nums);
        else
        {
            root->left=constructMax(l,max_ele,nums);
            root->right=constructMax(max_ele+1,r,nums);
        }
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMax(0,nums.size(),nums);
    }
};
// @lc code=end

