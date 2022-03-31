#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */
// 使用优先队列,每次pop出其中的一个,然后再将其后面的节点push
// 38.76% -- 16.93%




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
struct NodeIndex
{
    int index;
    ListNode* node;
    NodeIndex(int i,ListNode* n)
    {
        index=i;
        node=n;
    }
    bool operator >(const NodeIndex& b) const
    {
        if(node==nullptr) return true;
        if(b.node==nullptr) return false;

        if(node->val>b.node->val) return true;
        else if(node->val==b.node->val)
        {
            return index>b.index;
        }
        else
            return false;
    }
};

class Solution {
public:
    // bool Comp(const NodeIndex& a,const NodeIndex& b)
    // {
    //     if(a.node->val<b.node->val) return true;
    //     else if(a.node->val==b.node->val)
    //     {
    //         return a.index<b.index;
    //     }
    //     else
    //         return false;
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret=nullptr;
        if(lists.empty()) return ret;

        ListNode* p=ret;
        ListNode* tmp;
        int ind=0;

        // 首先进行特例处理
        priority_queue<NodeIndex,vector<NodeIndex>,greater<NodeIndex>> pv;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
                pv.push(NodeIndex(i,lists[i]));
        }
        while(!pv.empty())
        {
            // cout<<"***"<<endl;
            tmp=pv.top().node;
            ind=pv.top().index;

            // 进行替补增加
            pv.pop();
            if(tmp->next!=nullptr)
                pv.push(NodeIndex(ind,tmp->next));

            // 终止条件 以防万一
            if(tmp==nullptr) break;

            if(p==nullptr)
            {
                ret=new ListNode(tmp->val);
                p=ret;
            }
            else
            {
                p->next=new ListNode(tmp->val);
                p=p->next;
            }
        }
        return ret;
    }
};
// @lc code=end

