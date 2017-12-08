//
//  41 First Missing Positive.cpp
//  leetcode
//
//  Created by william wei on 08/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i=0; i<len; i++) {
            while (nums[i] > 0 && nums[i] <= len && nums[i] != i+1 && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i=0; i < len; i++) {
            if(nums[i]!= i+1) {
                return i+1;
            }
        }
        return len + 1;
    }
};

