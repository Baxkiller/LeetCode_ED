/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    vector<int> pre;
    vector<int> in;
    TreeNode* build(int beginA,int beginB,int cnt)
    {

        if(cnt==0) return nullptr;

        TreeNode* rt=new TreeNode(pre[beginA]);

        if(cnt ==1) return rt;

        int mid=find(in.begin(),in.end(),rt->val)-in.begin();
        int leftCnt=mid-beginB;
        int rightCnt=cnt-leftCnt-1;

        rt->left=build(beginA+1,beginB,leftCnt);
        rt->right=build(beginA+leftCnt+1,mid+1,rightCnt);
        return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 如果不止一个元素
        pre=preorder;
        in=inorder;
        return build(0,0,preorder.size());
    }
};
// @lc code=end

