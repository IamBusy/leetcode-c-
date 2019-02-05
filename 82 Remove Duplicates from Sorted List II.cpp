//
//  82 Remove Duplicates from Sorted List II.cpp
//  leetcode
//
//  Created by william wei on 2019/2/2.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 *  遍历链表，使用标量cnt记录当前节点vals出现的次数
 *  当cnt=1时，并且该节点的后一节点为空，或者值与当前值不同，则为非重复节点
 *  否则：若下一节点与当前节点值相同，cnt++，不同则置为1
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *first = head, *second=head, *result = NULL;
        int cnt = 1;
        int lastVal = head->val;
        while (first) {
            if (cnt == 1 && (
                             (first->next && first->next->val != first->val) ||
                             (! first->next))) {
                if (result == NULL) {
                    result = new ListNode(first->val);
                    second = result;
                    cnt = 1;
                } else {
                    second->next = new ListNode(first->val);
                    second = second->next;
                    cnt = 1;
                }
            } else {
                if (first->next && first->next->val == first->val) {
                    cnt++;
                } else {
                    cnt = 1;
                }
            }
            first = first->next;
        }
        return result;
    }
};

