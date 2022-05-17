/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        // 认为第一个节点是奇节点
        ListNode* ret=head;
        ListNode* jishu=head;
        ListNode* oushu_head=head->next;
        ListNode* oushu=oushu_head;
        ListNode* p=oushu->next;
        while(p!=nullptr)
        {
            jishu->next=p;
            jishu=jishu->next;
            p=p->next;
            oushu->next=p;
            if(p!=nullptr)
            {
                p=p->next;
                oushu=oushu->next;
            }
        }
        jishu->next=oushu_head;
        return ret;

    }
};
// @lc code=end

