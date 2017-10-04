//
//  26 Remove Duplicates from Sorted Array.cpp
//  leetcode
//
//  Created by william wei on 04/10/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unsigned long len = nums.size();
        if(len == 0) {
            return 0;
        } else if(len == 1) {
            return 1;
        }
        int last = 0;
        int idx = 1;
        int cnt = 1;
        while (idx < len) {
            if(nums[idx] != nums[last]) {
                cnt++;
                if(idx - last > 1) {
                    nums[last+1] = nums[idx];
                }
                last++;
            }
            idx ++;
        }
        nums.erase(nums.begin()+cnt,nums.end());
        return cnt;
    }
};
