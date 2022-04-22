/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
// 这就是报应
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 98.21
// ToBe Finished
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int index=-1;
        vector<int> nums;
        ListNode* retNode;
        ListNode* storeNode=head;
        while(head!=nullptr)
        {
            if(head->val>1e5)
            {// 这个点重复开始的点
                // 此时的index代表整个链表的所有数值
                // 需要保存这个节点  然后进行数值的恢复
                retNode=head;
                break;
            }
            else
            {// 如果这个点不是重复点
                nums.push_back(head->val);
                index++;
                head->val=1e5+1;
                head=head->next;
            }
        }
        // 判断是哪种情况跳出的循环
        if(head==nullptr) return nullptr;
        // 说明需要进行恢复
        int cur=0;
        while(storeNode!=retNode)
        {
            cur++;
            storeNode=storeNode->next;
        }
        for(int i=cur;i<nums.size();i++)
        {
            head->val=nums[i];
            head=head->next;
        }
        return retNode;


    }
};
// @lc code=end

