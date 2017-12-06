//
//  35 Search Insert Position.cpp
//  leetcode
//
//  Created by william wei on 27/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int mid;
        while (low < high) {
            mid = (low + high) /2;
            if(nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        mid = (low + high) /2;
        if(nums[mid] < target) {
            return mid + 1;
        } else {
            return mid;
        }
    }
};
