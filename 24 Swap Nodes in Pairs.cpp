//
//  24 Swap Nodes in Pairs.cpp
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

//ListNode* reverse(ListNode* start, ListNode*end) {
//    ListNode * temp;
//    return temp;
//}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int swapLen = 2;
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
