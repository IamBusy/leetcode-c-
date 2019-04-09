//
//  98 Validate Binary Search Tree.cpp
//  leetcode
//
//  Created by william wei on 2019/4/7.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*********************
 *   Version 2
 *********************/

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *cur = root;
        long lastVal = INT64_MIN;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            if (cur->val <= lastVal) {
                return false;
            }
            lastVal = cur->val;
            cur = cur->right;
        }
        return true;
    }
};



/*********************
 *   Version 1
 *********************/

//class Solution {
//public:
//    bool helper(TreeNode *node, long minN, long maxN) {
//        if ((node->val <= minN || node->val >= maxN) ||
//            (node->left && (node->val <= node->left->val || !helper(node->left, minN, min(maxN, long(node->val))))) ||
//            (node->right && (node->val >= node->right->val || !helper(node->right, max(minN, long(node->val)), maxN)))) {
//            return false;
//        }
//        return true;
//    }
//    bool isValidBST(TreeNode* root) {
//        if (root) {
//            return helper(root, INT64_MIN, INT64_MAX);
//        }
//        return true;
//    }
//};
