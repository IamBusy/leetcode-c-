//
//  81 Search in Rotated Sorted Array II.cpp
//  leetcode
//
//  Created by william wei on 2019/1/17.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1, mid;
        while (start < end) {
            mid  = (start + end) / 2;
            if (nums[mid] == target) {
                return false;
            } else if (nums[mid] > nums[end]) {
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[end] > target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};


