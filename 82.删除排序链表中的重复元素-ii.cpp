/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
// 最开始题意理解错误,以为是要去重,删除重复了的元素
// 再读一遍,发现是要将存在重复值得的元素删除
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
// 54.79--95.91
// 92.54--30
//1 1 2 2 3
// 1 1 2 2
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 特判
        if(head==nullptr || head->next==nullptr)
            return head;

        // 防止开头就是重复元素
        ListNode* pre=head;
        ListNode* cur=pre->next;
        if(pre->val!=cur->val)
            head=pre;
        else
        {
            while(cur!=nullptr)
            {
                if(cur->val==pre->val)
                {
                    cur=cur->next;
                }
                else
                {
                    if(pre->next!=cur)
                    {// 说明pre不是独一无二的
                        pre=cur;
                        cur=cur->next;
                    }
                    else

                    {// 说明pre是独一无二的
                        break;
                    }
                }
            }
            // 跳出时,应当有cur==null 或者pre->val !=cur->val
            // 一定可以保证pre是不含重复元素的
            // 但是不保证cur不含有重复元素
            // 先判断是否不含无重复元素的数值
            if(pre->next!=cur)
                return nullptr;
            else if(cur==nullptr)
                return pre;
            head=pre;
        }

        ListNode* nxt=cur->next;

        while(nxt!=nullptr)
        {
            if(nxt->val==cur->val)
                nxt=nxt->next;
            else
            {
                if(cur->next==nxt)
                {// 说明cur是独一无二的元素
                    pre->next=cur;
                    pre=cur;
                    cur=nxt;
                    nxt=nxt->next;
                }
                else
                {   // 说明cur是具有重复元素的
                    // 寄希望于nxt上
                    cur=nxt;
                    nxt=nxt->next;
                }
            }
        }
        // 此时nxt==nullptr
        if(cur->next!=nxt)
        {// 说明cur并不是单独的一个
            pre->next=nullptr;
        }
        else
            pre->next=cur;
        return head;
    }
};
// @lc code=end

