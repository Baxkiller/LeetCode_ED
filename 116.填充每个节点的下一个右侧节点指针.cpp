/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include <bits/stdc++.h>
#include "ThreeNode.h"
using namespace std;
// 84.81--84.52
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// 一个简单的层次遍历
class Solution {
public:
    Node* connect(Node* root) {

        Node* cur;
        Node* nxt=nullptr;
        Node* p;

        cur=root;

        while (cur!=nullptr)
        {
            if(cur->left==nullptr) return root;
            if(nxt==nullptr){
                nxt=cur->left;
                p=nxt;
                p->next=cur->right;
                p=p->next;
            }
            else{
                p->next=cur->left;
                p=p->next;
                p->next=cur->right;
                p=p->next;
            }

            if(cur->next==nullptr)
            {
                cur=nxt;
                nxt=nullptr;
            }
            else
                cur=cur->next;
        }

        return root;
    }
};
// @lc code=end

