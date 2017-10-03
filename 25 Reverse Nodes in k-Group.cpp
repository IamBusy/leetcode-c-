//
//  25 Reverse Nodes in k-Group.cpp
//  leetcode
//
//  Created by william wei on 03/10/2017.
//  Copyright © 2017 william wei. All rights reserved.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int swapLen = k;
        int idx = 0;
        ListNode* iter = head;
        ListNode* tmpHead = NULL;
        ListNode* tmpTail = NULL;
        ListNode** heap = new ListNode*[swapLen];
        while (iter != NULL) {
            heap[idx] = iter;
            iter = iter->next;
            idx++;
            if(idx == swapLen) {
                tmpTail = iter;
                for(int i=swapLen-1;i>0;i--) {
                    heap[i]->next = heap[i-1];
                }
                heap[0]->next = NULL;
                if(tmpHead) {
                    tmpHead->next = heap[swapLen-1];
                } else {
                    head = heap[swapLen-1];
                }
                tmpHead = heap[0];
                // Reset
                idx = 0;
            }
        }
        if(idx > 0) {
            if(tmpHead) {
                tmpHead->next = heap[0];
            }
            
        }
        return head;
    }
};
