/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// @lc code=start
// 序列化 可以进行中序遍历完成
class Codec {
public:
    string EncodeResult;
    void inOrder(TreeNode* r)
    {
        if(r==nullptr) return;
        EncodeResult+=to_string(r->val);
        EncodeResult.push_back(' ');
        inOrder(r->left);
        inOrder(r->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        EncodeResult="";
        inOrder(root);
        return EncodeResult;
    }

    // Decodes your encoded data to tree.
    // 解码 中序遍历 给定一行字符串
    TreeNode* root;
    // 声明左闭右开
    void Insert(int number)
    {
        TreeNode* par;
        TreeNode* cur;

        if(root==nullptr)
        {
            root=new TreeNode(number);
            return;
        }

        par=root;
        cur=root;

        while(cur!=nullptr)
        {
            if(number>cur->val)
                par=cur,cur=cur->right;
            else
                par=cur,cur=cur->left;
        }
        cur=new TreeNode(number);
        if(number<par->val)
            par->left=cur;
        else
            par->right=cur;
        
        return;
    }

    TreeNode* deserialize(string data) {
        // 先将内容从string 转化为vector
        delete root;
        root=nullptr;
        stringstream ss;
        ss<<data;
        while(getline(ss,data,' '))
        {
            Insert(atoi(data.data()));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

