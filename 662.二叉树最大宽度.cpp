/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        int ret=0;
        while(!q.empty())
        {
            int cnt=q.size();
            ret=max(ret,cnt);

            while(cnt--)
            {
                TreeNode* f=q.front();
                q.pop_front();

                if(f==nullptr)
                {
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                }
                else
                {
                    q.push_back(f->left);
                    q.push_back(f->right);
                }
            }
            while(q.back()==nullptr)
                q.pop_back();
        }
        return ret;
    }
};
// @lc code=end
// [1,3,2,5,null,null,9,6,null,null,null,null,null,null,7]
// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
