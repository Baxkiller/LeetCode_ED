/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 初始题解
// 开始想着先求两个数字,然后求和再转化为链表  ,结果发现某些部分的数字长度超过了long long类型
// 本次提交成功的结果中需要注意:
// - 如果长度等长
//      - 最后是否产生了进位
// - 如果长度不相等
//      - 哪个长度更小一些
//      - 长度更长的是否最后产生进位
//  long long GetCount(ListNode* in)
// {
//     long long Count1=0;
//     long long mult=1;
//     while (in !=nullptr)
//     {
//         Count1+=(in->val)*mult;
//         in=in->next;
//         mult*=10;
//     }
//     return Count1;
// }

// ListNode* MakeList(long long count)
// {
//     if(count==0)
//     {
//         return new ListNode(0,nullptr);
//     }
//     ListNode* res=nullptr;
//     while(count!=0)
//     {
//         ListNode* cur=new ListNode(count%10,res);
//         res=cur;
//         count/=10;
//     }
    
//     // reverse the list
//     ListNode* pre=nullptr;
//     ListNode* cur=res;
//     ListNode* nxt=res->next;
//     while(nxt!=nullptr)
//     {
//         cur->next=pre;
//         pre=cur;
//         cur=nxt;
//         nxt=nxt->next;
//     }
//     cur->next=pre;
//     return cur;
// }


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool add=0;
        ListNode* res=new ListNode;
        ListNode* ret=res;
        int tmpSum=0;
        bool head=1;
        while(l1!=nullptr && l2!=nullptr)
        {
            tmpSum=l1->val+l2->val+add;
            if(tmpSum>=10)
            {
                tmpSum%=10;
                add=1;
            }
            else{
                add=0;
            }
            res->next=new ListNode(tmpSum);
            l1=l1->next;
            l2=l2->next;
            res=res->next;
            if(head)
            {
                ret=res;
                head=false;
            }
        }
        // 如果其中一个到达尽头,应当将另外一个原样复制过来
        ListNode* nxt=nullptr;
        if(l1==nullptr && l2!=nullptr)
            nxt=l2;
        else if(l1!=nullptr)
            nxt=l1;
        else
        {
            if(add)
            {
                res->next=new ListNode(add);
            }
            return ret;
        }
        
        // 如果其中有一个没有结束
        while(nxt!=nullptr)
        {
            tmpSum=nxt->val+add;
            if(tmpSum>=10)
            {
                tmpSum%=10;
                add=1;
            }
            else{
                add=0;
            }
            res->next=new ListNode(tmpSum);
            nxt=nxt->next;
            res=res->next;
        }
        if(add)
        {
            res->next=new ListNode(add);
        }
        return ret;
        
    }
};
// @lc code=end

