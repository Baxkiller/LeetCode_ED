/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */
#include <bits/stdc++.h>
using namespace std;
// 初始题解 想要通过一次遍历完成搜索,也就是每次对比游标指向的和与当前的目标值大小关系,进而移动游标,问题在于算法初始即错误
// 后来的求解:如果使用unordered_map和unordered_set进行计算,发现内容存在遗留!!猜测可能由于将nums设置为全局变量而不是类内变量
// 修改后想到能否利用二叉搜索树的性质,直接进行排序,将结果放在vector中,此时是有序的.然后通过二分搜索尝试找到想要的内容,速度快
// TreeNode* leftNode=root;
// TreeNode* rightNode=root;
// int leftVal,rightVal;
// while(leftNode!=nullptr && rightNode!=nullptr)
// {
//     leftVal=leftNode->val;
//     rightVal=rightNode->val;
//     if(leftVal+rightVal==k && leftNode!=rightNode)
//         return true;
//     if(leftVal+rightVal > k)
//     {
//         if(leftNode->left!=nullptr)
//             leftNode=leftNode->left;
//         else
//             rightNode=rightNode->left;
//     }
//     else if(leftVal+rightVal<k)
//     {
//         if(leftNode->right!=nullptr && leftNode!=root)
//             leftNode=leftNode->right;
//         else
//             rightNode=rightNode->right;
//     }
//     else
//     {
//         leftNode=leftNode->left;
//     }
// }
// return false;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


// 题解:
// 采用类似游标的方式进行求解.

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
    vector<int> nums;
    void access(TreeNode* t)
    {
        if(t==NULL) return;

        access(t->left);
        nums.push_back(t->val);
        access(t->right);

    }
    bool findTarget(TreeNode* root, int k) {
        access(root);
        for(int i=0;i<nums.size();i++)
        {
        cout<<nums.size()<<endl;
            auto findres=find(nums.begin()+i,nums.end(),k-nums[i]);
            cout<<*findres<<" "<<nums[i]<<endl;
            if(findres!=nums.end())
            {
                if(*findres != nums[i]) 
                {
                    nums.clear();
                    return true;
                }
            }
        }
        nums.clear();
        return false;
    }
};
// @lc code=end

