/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
 */
#include "bits/stdc++.h"
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
    vector<int> ret;
    int position;
    void recursion(TreeNode* root)
    {
        if(root==NULL) return;
        if(root->left!=NULL)
            recursion(root->left);
        ret.push_back(root->val);
        if(root->right!=NULL)
            recursion(root->right);
        return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // 应该进行 中序遍历
        recursion(root1);
        vector<int> tmp=ret;
        ret.clear();
        recursion(root2);
        vector<int> ans;
        int a=0,b=0;
        while(a<tmp.size() && b<ret.size())
        {
            if(tmp[a]<=ret[b])
                ans.push_back(tmp[a++]);
            else
                ans.push_back(ret[b++]);
        }
        if(a==tmp.size())
        {
            while(b<ret.size()) ans.push_back(ret[b++]);
        }
        else
            while(a<tmp.size()) ans.push_back(tmp[a++]);
        
        return ans;
    }
};
// @lc code=end

