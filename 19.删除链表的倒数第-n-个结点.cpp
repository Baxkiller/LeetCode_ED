#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // 要首先遍历一遍确定总共的数量?
        ListNode* nxt=head;
        int count=0;
        while(nxt!=nullptr)
        {
            count++;
            nxt=nxt->next;
        }
        cout<<count<<endl;

        n=count-n;
        // 特判处理 确定要删除的是不是头节点
        if(n==0) return head->next;


        ListNode* pre=head;
        while(--n)
        {
            pre=pre->next;
        }
        //此时找到的nxt就是要删除的节点的前一个节点
        pre->next=pre->next->next;
        return head;
    }
};
// @lc code=end

