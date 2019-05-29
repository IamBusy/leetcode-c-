//
//  101 Symmetric Tree.cpp
//  leetcode
//
//  Created by william wei on 2019/5/28.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>

#include <queue>
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
    bool isSymmetric(TreeNode*p, TreeNode*q) {
        if (p == NULL && q == NULL) {
            return true;
        } else {
            return p && q && p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
        }
    }
    bool isSymmetric(TreeNode* root) {
        return !root || isSymmetric(root->left, root->right);
    }
    
    bool isSymmetricNonRecursive(TreeNode* root) {
        if (!root) {
            return true;
        }
        stack<TreeNode *> st;
        TreeNode *left, *right;
        st.push(root->right);
        st.push(root->left);
        while (st.size() >= 2) {
            left = st.top();
            st.pop();
            right = st.top();
            st.pop();
            if ((left == NULL) != (right == NULL)) {
                return false;
            }
            if (left == NULL && right == NULL) {
                continue;
            }
            if (left->val == right->val) {
                st.push(left->right);
                st.push(right->left);
                st.push(left->left);
                st.push(right->right);
            } else {
                return false;
            }
        }
        return true;
    }
};
