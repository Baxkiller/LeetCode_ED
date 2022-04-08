/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        // 遍历一遍 设置为数组形式
        ListNode* nums[100];
        int index=0;
        while(head!=nullptr)
        {
            nums[index++]=head;
            head=head->next;
        }
        return nums[index/2];
    }
};
// @lc code=end

