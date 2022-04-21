/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 肯定要对链表节点进行标识
        // 例如直接记录指针值 然后进行比较
        // 记录value值然后比较肯定不行
        // 对于比较来说,每次找到一个节点都需要从头开始逐个对比吗
        // 时间复杂度太高
        // 可以每次遍历到节点,将其值设置为1e5+1
        // 然后判断遍历到的节点是否出现这个值即可
        while(head!=nullptr)
        {
            if(head->val==1e5+1) return true;
            head->val=1e5+1;
            head=head->next;
        }
        return  false;

    }
};
// @lc code=end

