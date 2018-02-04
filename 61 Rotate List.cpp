//
//  61 Rotate List.cpp
//  leetcode
//
//  Created by william wei on 04/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (! head) {
            return NULL;
        }
        int len = 1;
        ListNode *cursor = head;
        while (cursor->next) {
            cursor = cursor->next;
            len++;
        }
        ListNode *mid = head, *newHead = head;
        if (k%len) {
            for (int i=len - k % len - 1; i > 0; i--) {
                mid = mid->next;
            }
            cursor->next = head;
            newHead = mid->next;
            mid->next = NULL;
        }
        return newHead;
    }
};
