//
//  21 Merge Two Sorted Lists.cpp
//  leetcode
//
//  Created by william wei on 17/09/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* ptr = res;
        ListNode* first = l1;
        ListNode* second = l2;
        while (first && second) {
            if(first->val < second->val) {
                ptr->next = first;
                ptr = first;
                first = first->next;
            } else{
                ptr->next = second;
                ptr = second;
                second = second->next;
            }
        }
        if(first) {
            ptr->next = first;
        }
        if(second) {
            ptr->next = second;
        }
        return res->next;
    }
};
