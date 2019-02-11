//
//  86 Partition List.cpp
//  leetcode
//
//  Created by william wei on 2019/2/11.
//  Copyright © 2019 william wei. All rights reserved.
//
#include <stdio.h>
using namespace std;
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
    ListNode* partition(ListNode* head, int x) {
        ListNode first = ListNode(0);
        ListNode *firstIter = &first;
        ListNode mid = ListNode(0);
        ListNode second = ListNode(0);
        ListNode *secondIter = &second;
        ListNode *iter = head;
        while (iter) {
            if (iter->val < x) {
                firstIter->next = iter;
                firstIter = iter;
            } else {
                secondIter->next = iter;
                secondIter = iter;
            }
            iter = iter->next;
        }
        firstIter->next = second.next;
        secondIter->next = NULL;
        return first.next;
    }
};
