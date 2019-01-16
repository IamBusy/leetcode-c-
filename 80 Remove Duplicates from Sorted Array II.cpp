//
//  80 Remove Duplicates from Sorted Array II.cpp
//  leetcode
//
//  Created by william wei on 2019/1/16.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) {
            return nums.size();
        }
        int head = 2, second = 0, tail = 2;
        while (head < nums.size()) {
            if (!(nums[head] == nums[tail-1] && nums[head] == nums[tail-2])) {
                swap(nums[head], nums[tail++]);
            }
            head++;
        }
        return tail;
    }
};
