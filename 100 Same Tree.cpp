//
//  100 Same Tree.cpp
//  leetcode
//
//  Created by william wei on 2019/5/28.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        } else {
            if (p && q && p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right)) {
                return true;
            }
            return false;
        }
    }
};
