//
//  94 Binary Tree Inorder Traversal.cpp
//  leetcode
//
//  Created by william wei on 2019/3/16.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//    void travel(TreeNode *node, vector<int>&res) {
//        if (node->left) {
//            travel(node->left, res);
//        }
//        res.push_back(node->val);
//        if (node->right) {
//            travel(node->right, res);
//        }
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        if (root) {
//            travel(root, res);
//        }
//        return res;
//    }
//};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                auto p = st.top();
                res.push_back(p->val);
                st.pop();
                node = p->right;
            }
        }
        return res;
    }
};

