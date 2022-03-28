#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;


/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
// 初始题解,直接构造一条新的链表,然后每次都对新的链表操作
// 但是最终结果不是特别理想,时间60.89% 空间5.02%
/*
// 相当于双指针的排序
// 特判
if(list1==nullptr) return list2;
if(list2==nullptr) return list1;

// 确保两个开始都不是null
ListNode* ret=new ListNode;
if(list1->val<list2->val)
{
    ret->val=list1->val;
    list1=list1->next;
}
else
{
    ret->val=list2->val;
    list2=list2->next;
}
ListNode* p=ret;
while(list1!=nullptr && list2!=nullptr)
{
    if(list1->val<list2->val)
    {
        p->next=new ListNode(list1->val);
        list1=list1->next;
    }
    else
    {
        p->next=new ListNode(list2->val);
        list2=list2->next;
    }
    p=p->next;
}

if(list1==nullptr)
    p->next=list2;
else
    p->next=list1;
return ret;

*/

// 忽然想到,能否通过在原有链表的基础上进行改动
// 而不需要进行额外空间的申请和占用
// 效果拔群! 92.96%-98.23%


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode* m;ListNode *nn;
        ListNode * tmp;ListNode *ret;
        if(list1->val<list2->val) m=list1,nn=list2;
        else m=list2,nn=list1;

        ret=m;

        while(m->next!=nullptr && nn!=nullptr)
        {
            if((m->next->val)>(nn->val))
            {
                tmp=nn;
                nn=nn->next;
                tmp->next=m->next;
                m->next=tmp;
                tmp=nullptr;
                m=m->next;
            }
            else
            {
                m=m->next;
            }
        }

        if(m->next==nullptr)
        {
            m->next=nn;
        }
        return ret;
    }
};
// @lc code=end

