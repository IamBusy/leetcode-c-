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
        while (idx < nums.size()) {
            if(nums[idx] != nums[last]) {
                if(idx - last > 1) {
                    nums.erase(nums.begin()+last+1, nums.begin()+idx);
                    last++;
                    idx = last;
                } else {
                    last++;
                }
            }
            idx ++;
        }
        if(last < nums.size()-1 && nums[nums.size()-1] == nums[last]){
            nums.erase(nums.begin()+last+1,nums.end());
        }
        return nums.size();
    }
};
