//
//  53 Maximum Subarray.cpp
//  leetcode
//
//  Created by william wei on 01/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int maxNum = INT_MIN;
        int tmpSum = 0;
        for (int i=nums.size()-1; i>=0; i--) {
            maxNum = nums[i]>maxNum? nums[i]: maxNum;
            if (tmpSum + nums[i] > 0) {
                tmpSum += nums[i];
                maxSum = tmpSum>maxSum? tmpSum: maxSum;
            } else {
                tmpSum = 0;
            }
        }
        return maxSum>maxNum? maxSum: maxNum;
    }
};
