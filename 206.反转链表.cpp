/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
// leetCode的随机性太强了
// 连续三次 最低64--60+
// 最高 95.55--98
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
    ListNode* reverseList(ListNode* head) {
        // 特判
        if(head==nullptr || head->next==nullptr)
            return head;
        // 原地反转 通过特判保证了pre cur 不是null
        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* nxt=cur->next;
        while(nxt!=nullptr)
        {
            cur->next=pre;
            pre=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        // nxt==nullptr
        cur->next=pre;
        head->next=nullptr;// 处理闭环
        return cur;
    }
};
// @lc code=end

