//
//  95 Unique Binary Search Trees II.cpp
//  leetcode
//
//  Created by william wei on 2019/4/5.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* copyTree(TreeNode* root) {
    TreeNode *newRoot = NULL;
    if (root) {
        newRoot = new TreeNode(root->val);
        newRoot->left = copyTree(root->left);
        newRoot->right = copyTree(root->right);
    }
    return newRoot;
}

TreeNode *find(TreeNode *root, int x) {
    TreeNode *curr = root;
    while (curr) {
        if (x == curr->val) {
            return curr;
        } else if (x > curr->val) {
            curr = curr->right;
        } else {
            curr = curr->left;
        }
    }
    return NULL;
}

class Solution {
public:
    void insert(TreeNode *root, int n, vector<TreeNode*> &res) {
        TreeNode *newRoot = copyTree(root);
        int target = root->val;
        TreeNode *curNode = NULL;
        while (target > 0 && (curNode = find(newRoot, target)) && curNode) {
            TreeNode *inserted = new TreeNode(n);
            // n is must bigger then any vals of the tree
            inserted->left = curNode->right;
            curNode->right = inserted;
            res.push_back(newRoot);
            
            if(inserted->left) {
                target = inserted->left->val;
                newRoot = copyTree(root);
            } else {
                target = 0;
            }
        }
    }
    void helper(int n, vector<TreeNode*>&results) {
        int len = results.size();
        for (int i=0; i<len; i++) {
            TreeNode *oldRoot = results[i];
            TreeNode *root = new TreeNode(n);
            root->left = oldRoot;
            results[i] = root;
            insert(oldRoot, n, results);
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>res = vector<TreeNode*>(0);
        if (n > 0) {
            res.push_back(new TreeNode(1));
            for (int i=2; i<=n; i++) {
                helper(i, res);
            }
        }
        return res;
    }
};
