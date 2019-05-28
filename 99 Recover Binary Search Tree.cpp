//
//  99 Recover Binary Search Tree.cpp
//  leetcode
//
//  Created by william wei on 2019/4/10.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *cur = root;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        TreeNode *pre = NULL;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            // If pre is null, first will be also null.
            if (first == NULL && (pre == NULL || pre->val >= cur->val)) {
                first = pre;
            }
            // find the last pair which the second value is smaller than the first one
            if (first != NULL && (pre->val >= cur->val)) {
                second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};
