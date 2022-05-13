/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
/* 初始想法 存在弊端 即无法使得最后的不满足的节点仍然保持原有顺序
if(k==1) return head;

        int cnt=0;
        // head and tail pointer
        ListNode* h;
        ListNode* cur,*pre,*nxt;

        cur=head,nxt=head->next;
        pre=h=new ListNode(-1,head);
        ListNode* anchor=h;

        while(cur!=nullptr)
        {
            nxt=cur->next;
            cur->next=pre;

            pre=cur;
            cur=nxt;
            nxt=cur->next;
            cnt++;

            if(cnt==k)
            {// 说明已经转换了k个节点了
                cnt=0;
                ListNode* fir=h->next;
                fir->next=cur;
                h->next=pre;

                h=fir;
                pre=h;
            }
        }
*/


// @lc code=start
class Solution {
public:
    ListNode* transNode(ListNode* cur)
    {
        ListNode* nxt=cur->next;
        ListNode* pre=nullptr;
        while (nxt!=nullptr)
        {
            cur->next=pre;
            pre=cur;
            cur=nxt;
            nxt=nxt->next;
        }
        cur->next=pre;
        return cur;
    }
// 如果想保持原有顺序 就要以时间换空间
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1) return head;

        ListNode* header;
        ListNode* header_nxt;
        ListNode* tail;
        ListNode* cur;

        cur=head;
        header=new ListNode(-1,head);
        header_nxt=head;

        ListNode* anchor=header;

        int cnt=1;

        while(true)
        {
            cur=cur->next;
            cnt++;

            if(cur==nullptr) break;
            if(cnt==k)
            {
                cnt=1;

                tail=cur->next;
                cur->next=nullptr;
                
                header->next=transNode(header_nxt);

                // ListNode* debug=header->next;
                // while(debug!=nullptr)
                // {
                //     cout<<debug->val<<" ";
                //     debug=debug->next;
                // }
                // cout<<endl;
                if(tail!=nullptr)
                {
                    header=header_nxt;
                    header_nxt->next=tail;
                    header_nxt=tail;
                    cur=tail;
                }
                else
                    break;
            }
        }
        return anchor->next;
    }
};
// @lc code=end

