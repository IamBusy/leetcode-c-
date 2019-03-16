//
//  92 Reverse Linked List II.cpp
//  leetcode
//
//  Created by william wei on 2019/3/14.
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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        ListNode *starter = new ListNode(0);
        starter->next = head;
        ListNode *cursor = starter;
        ListNode *frontPartEnd = NULL;
        ListNode *partStart = NULL;
        ListNode *partEnd = NULL;
        int idx = 0;
        while (idx <= n) {
            idx++;
            if (idx < m) {
                if (idx == m-1) frontPartEnd = cursor;
                cursor = cursor->next;
                continue;
            } else if (idx > m) {
                auto tmp = cursor->next;
                cursor->next = partStart;
                partStart = cursor;
                cursor = tmp;
            } else {
                partEnd = cursor;
                cursor = cursor->next;
            }
        }
        frontPartEnd->next = partStart;
        partEnd->next = cursor;
        return starter->next;
    }
};
