//
//  83 Remove Duplicates from Sorted List.cpp
//  leetcode
//
//  Created by william wei on 2019/2/5.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (! head) {
            return NULL;
        }
        ListNode *first = head->next;
        ListNode *second = head;
        while (first) {
            if (first->val != second->val) {
                second->next = first;
                second = first;
            }
            first = first->next;
        }
        second->next = NULL;
        return head;
    }
};
