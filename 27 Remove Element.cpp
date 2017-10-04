//
//  27 Remove Element.cpp
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
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) {
            return 0;
        }
        int last = 0, cnt = 1,len = nums.size(),i;
        while (last< len) {
            if(nums[last] != val) {
                nums[0] = nums[last];
                i = last+1;
                last = 0;
                break;
            }
            last++;
        }
        if(last == len) {
            return 0;
        }
        for (; i<nums.size(); i++) {
            if(nums[i] !=  val) {
                if(last+1 != i) {
                    nums[last+1] = nums[i];
                }
                last++;
                cnt++;
            }
        }
        return cnt;
    }
};
