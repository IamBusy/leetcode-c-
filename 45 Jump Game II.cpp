//
//  45 Jump Game II.cpp
//  leetcode
//
//  Created by Wei,Xiaole on 24/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2) {
            return 0;
        }
        int low = 1, high = nums[0] + 1, level = 1;
        int maxHigh = 0;
        while (high < nums.size()) {
            for (int i=low; i<high; i++) {
                if(i + nums[i] > maxHigh) {
                    maxHigh = i + nums[i];
                }
            }
            low = high;
            high = maxHigh+1;
            maxHigh = 0;
            level++;
        }
        return level;
    }
};
