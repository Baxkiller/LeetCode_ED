/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 两两交换
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* ppre=new ListNode(-1,head);
        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* nxt=cur->next;

        ListNode* ret=ppre;

        while(pre!=nullptr && cur!=nullptr)
        {
            ppre->next=cur;
            cur->next=pre;
            pre->next=nxt;

            // 向后移动
            ppre=pre;
            pre=nxt;
            if(pre!=nullptr) cur=pre->next;
            if(cur!=nullptr) nxt=cur->next;
        }
        return ret->next;
    }
};
// @lc code=end

