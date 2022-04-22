/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;
// 普通的遍历时间复杂度恐怕会达到O(n^2)
// 如果考虑空间换时间,可以放在vector,调用排序
// 再构建链表 
// 38--46 事实上速度也不快
/*
        vector<int> nums;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            nums.push_back(cur->val);
            cur=cur->next;
        }
        cur=head;
        sort(nums.begin(),nums.end());
        for(auto &it:nums)
        {
           cur->val=it;
           cur=cur->next; 
        }
        return head;
*/
// 看了其他人的题解,可以使用归并排序+dummyhead
// @lc code=start
class Solution {
public:
    // 将传入的两个有序链表进行合并,返回合并后的头节点
    ListNode* Merge(ListNode* left,ListNode* right);
    // 包括当前节点 向后截取n=count 个
    // 返回的是截取后的节点指针
    ListNode* cut(ListNode* &head,int count);

    ListNode* sortList(ListNode* head) {
        // 进行递归操作
        if(head==nullptr) return nullptr;
        ListNode* nxt;
        queue<ListNode*> ordered;
        // 拆分成单个链表
        while(head!=nullptr)
        {
            nxt=cut(head,1);
            ordered.push(head);
            head=nxt;
        }

        while(ordered.size()>1)
        {
            int n=ordered.size();
            cout<<n<<endl;
            if(n&1){
                n--;
                ordered.push(ordered.front());
                ordered.pop();
            }
            ListNode* l,*r;
            n/=2;
            while(n--)
            {// 循环合并
                l=ordered.front();
                ordered.pop();
                r=ordered.front();
                ordered.pop();
                // cout<<"Merge"<<l->val<<" "<<r->val<<endl;
                l=this->Merge(l,r);
                ordered.push(l);
            }
        }
        return ordered.front();
        
    }
};

ListNode* Solution::Merge(ListNode* left,ListNode* right)
{
    if(left==nullptr) return right;
    if(right==nullptr) return left;
    ListNode* tmp;
    ListNode* pre;
    if(left->val>right->val)
    {// 将小值看作是left
        // cout<<left->val<<" "<<right->val<<endl;
        tmp=left;
        left=right;
        right=tmp;
    }
    tmp=left;
    pre=left;
    left=left->next;
    while(left!=nullptr && right!=nullptr)
    {
        // 将较大者添加到left后面
        if(right->val<left->val)
        {
            pre->next=right;
            right=right->next;
            pre->next->next=left;
            left=pre->next;
        }
        else
        {
            left=left->next;
            pre=pre->next;
        }
    }
    // 有一方为空
    if(right==nullptr) return tmp;
    // 如果左侧为空了,那么说明右侧还剩余节点呢
    pre->next=right;
    return tmp;
}

// 包含当前的节点
ListNode* Solution::cut(ListNode* &head,int count)
{
    // 链表的返回节点
    ListNode* ret=head;
    count--;
    
    while(head!=nullptr && count--)
    {
        head=head->next;
    }
    
    if(head==nullptr) return nullptr;

    // 如果后续不够count个,也不要紧  直接返回即可
    ret=head->next;
    head->next=nullptr;
    return ret;
}
// @lc code=end

