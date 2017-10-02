//
//  23 Merge k Sorted Lists.cpp
//  leetcode
//
//  Created by william wei on 02/10/2017.
//  Copyright © 2017 william wei. All rights reserved.
//


// Definition for singly-linked list.
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool comp (ListNode *node1, ListNode *node2) {
    return node1->val > node2->val;
}


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (vector<ListNode*>::iterator iter= lists.begin();
             iter != lists.end(); iter++)
        {
            if(*iter == NULL) {
                lists.erase(iter);
                iter--;
            }
        }
        make_heap(lists.begin(), lists.end(),comp);
        ListNode* first = new ListNode(0);
        ListNode* iter = first;
        while (lists.size()>0) {
            iter->next = lists.front();
            pop_heap(lists.begin(), lists.end(),comp);
            lists.pop_back();
            iter = iter->next;
            if(iter->next != NULL) {
                lists.push_back(iter->next);
                push_heap(lists.begin(), lists.end(),comp);
            }
        }
        return first->next;
    }
};
