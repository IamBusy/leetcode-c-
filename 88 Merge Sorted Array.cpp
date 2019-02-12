//
//  88 Merge Sorted Array.cpp
//  leetcode
//
//  Created by william wei on 2019/2/12.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m+n-1, idx1 = m-1, idx2 = n-1;
        while (idx>=0 && idx1>=0 && idx2>=0) {
            nums1[idx--] = nums1[idx1] >= nums2[idx2]? nums1[idx1--]: nums2[idx2--];
        }
        while (idx>=0) {
            nums1[idx--] = (idx1>=0)?nums1[idx1--]: nums2[idx2--];
        }
    }
};
