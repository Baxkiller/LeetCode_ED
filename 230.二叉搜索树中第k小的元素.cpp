/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
// 考虑到是二叉搜索树,因此要进行完整从大到小的遍历
// 对应于二叉搜索树的中序遍历
// 只需要将visit函数设置为检查此时visit的点的下标即可
class Solution {
public:
    bool visit(int k){return idex==k;}
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return -1111111;
        int lval=kthSmallest(root->left,k);
        if(lval != -1111111)
            return lval;
        if(visit(k)) return root->val;
        idex++;
        return kthSmallest(root->right,k);
    }
private:
    int idex=1;
};
// @lc code=end

