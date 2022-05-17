/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
// 将链表反转  然后返回反转后的链表头节点
    ListNode* reverseList(ListNode* head)
    {
        if(head->next==nullptr) return head;

        ListNode* pre=head;
        ListNode* cur=head->next;
        ListNode* nxt=cur->next;
        head->next=nullptr;

        while(nxt!=nullptr)
        {
            cur->next=pre;
            pre=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        cur->next=pre;
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        // 进行加法操作
        int plus=0;
        ListNode* ret=l1;
        while(l1->next!=nullptr && l2->next!=nullptr)
        {
            l1->val+=l2->val+plus;
            // 进位的处理
            if(l1->val>=10)
            {
                l1->val-=10;
                plus=1;
            }
            else
                plus=0;

            l1=l1->next;
            l2=l2->next;
        }
        
        // 先将当前的没有处理的l1和l2相加
        l1->val+=l2->val+plus;
        if(l1->val>9)
            l1->val-=10,plus=1;
        else
            plus=0;

        // 将不为空的那一条链的后部部分嫁接到当前的l1链的后续中
        if(l1->next==nullptr)
            l1->next=l2->next;

        // l1=l1->next;

        while(l1->next!=nullptr && plus==1)
        {
            l1=l1->next;
            l1->val+=1;
            if(l1->val>9) l1->val-=10,plus=1;
            else plus=0;
        }

        if(plus==1 && l1->next==nullptr)
            l1->next=new ListNode(1,nullptr);

        return reverseList(ret);
        
    }
};
// @lc code=end

