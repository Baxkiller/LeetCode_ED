/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */
/*
vector<int> Count;
    // 以head为开头,分配count个节点 返回下一个开头
    ListNode* split(ListNode* head,int count)
    {
        if(count==0 || head==nullptr) return nullptr;
        ListNode* nxt=head->next;
        count--;
        while(count--)
        {
            head=nxt;
            nxt=nxt->next;
        }
        head->next=nullptr;
        return nxt;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // 首先进行组内的划分.所以应该先遍历一遍得到节点总数
        // 以及根据节点总数得到每一部分应该有多少
        int cnt=0;
        ListNode* p=head;
        while(p!=nullptr)
        {
            p=p->next;
            cnt++;
        }

        int base=cnt/k;
        int exp=cnt-base*k;
        
        // 进行节点分配
        ListNode* h=head;
        vector<ListNode*> ret;
        ret.reserve(k);
        ret.push_back(h);
        
        int i=0;
        for(i=0;i<exp;i++)
        {
            h=split(h,base+1);
            ret.push_back(h);
        }
        for(;i<k-1;i++)
        {
            h=split(h,base);
            ret.push_back(h);
        }
        return ret;
    }
*/
#include "ListNode.h"
#include <bits/stdc++.h>
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
    // 无法通过仅仅一次遍历实现这个功能
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {// 我直接进行一次遍历就好了
        // vector<ListNode*> ret;
        // vector<ListNode*> cur;
        // ret.reserve(k);
        // cur.reserve(k);
        // int index=0;
        // int i=0;
        // for(i=0;i<k && head !=nullptr;i++)
        // {
        //     ret.push_back(head);
        //     cur.push_back(head);
        //     head=head->next;
        //     cur[i]->next=nullptr;
        // }
        // if(i!=k)
        // {
        //     while(i!=k)
        //     {
        //         ret.push_back(nullptr);
        //         i++;
        //     }
        //     return ret;
        // }
        

        // i=0;
        // while(head!=nullptr)
        // {
        //     cur[i]->next=head;
        //     head=head->next;
        //     cur[i]=cur[i]->next;
        //     cur[i]->next=nullptr;
        //     i=(i+1)%k;
        // }
        // return ret;
    }
};
// @lc code=end

