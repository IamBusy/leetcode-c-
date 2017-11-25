//
//  31 Next Permutation.cpp
//  leetcode
//
//  Created by william wei on 25/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//
#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int cnt = nums.size();
        for (int i=nums.size()-1; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                // Reverse
                for (int j=(cnt-1-i)/2+i; j>=i; j--) {
                    swap(nums[j], nums[cnt-1+i-j]);
                }
                for (int j=i; j<cnt; j++) {
                    if(nums[j]>nums[i-1]) {
                        swap(nums[j], nums[i-1]);
                        return;
                    }
                }
            }
        }
        for (int i=(cnt-1)/2; i>=0; i--) {
            swap(nums[i], nums[cnt-1-i]);
        }
    }
};
