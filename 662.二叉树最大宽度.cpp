/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
 */

/*
 超出时间限制
if(root==nullptr) return 1;

        deque<TreeNode*> q;
        q.push_back(root);

        int ret=1;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                TreeNode* cur=q.front();
                q.pop_front();
                if(cur==nullptr)
                {
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                }
                else
                {
                    q.push_back(cur->left);
                    q.push_back(cur->right);
                }
            }

            while(!q.empty() && q.front() == nullptr)
                q.pop_front();
            while(!q.empty() && q.back() == nullptr)
                q.pop_back();
            
            n=q.size();
            if(ret<n) ret=n;
        }
        return ret;
*/

/*
新的想法是通过dfs,使用long long 表示每个节点的下标,进行dfs
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
        queue<TreeNode*> level;
        queue<int> indexs;

        level.push(root);
        indexs.push(1);

        int size=0;
        int ret=1;
        while(!level.empty())
        {
            size=level.size();
            
            int begin_index=indexs.front();
            int end_index=indexs.back();
            ret=max(ret,end_index-begin_index+1);

            while(size--)
            {
                TreeNode* p=level.front();
                level.pop();
                int index=indexs.front();
                indexs.pop();

                if(p->left!=nullptr)
                {
                    level.push(p->left);
                    indexs.push(index*2);
                }
                
                if(p->right!=nullptr)
                {
                    level.push(p->right);
                    indexs.push(index*2+1);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
// [1,3,2,5,null,null,9,6,null,null,null,null,null,null,7]
// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
