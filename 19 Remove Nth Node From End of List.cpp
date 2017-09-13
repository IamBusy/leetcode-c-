//
//  19 Remove Nth Node From End of List.cpp
//  leetcode
//
//  Created by william wei on 13/09/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* target = NULL;
        ListNode* ptr = head;
        for (;n>0; n--) {
            ptr = ptr->next;
        }
        if(ptr != NULL) {
            target = head;
            ptr = ptr->next;
        } else {
            return head->next;
        }
        while (ptr != NULL) {
            ptr = ptr->next;
            target = target->next;
        }
        target->next = target->next->next;
        return head;
    }
};
