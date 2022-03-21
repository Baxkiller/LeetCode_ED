#include <bits/stdc++.h>
using namespace std;


//* Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


queue<TreeNode*> nodes;
set<int> nums;
int kthSmallest(TreeNode* root, int k) 
{
    nodes.push(root);
    while(!nodes.empty())
    {
        TreeNode* c=nodes.front();
        nodes.pop();
        nums.emplace(c->val);
        if(c->left!=NULL) nodes.push(c->left);
        if(c->right!=NULL) nodes.push(c->right);
    }
    int i=0;
    for(auto it:nums)
        if(i==k) return it;
        else i++;
    return -1;
}