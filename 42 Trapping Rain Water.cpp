//
//  42 Trapping Rain Water.cpp
//  leetcode
//
//  Created by Wei,Xiaole on 20/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sums = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;
        while (left < right) {
            if(height[left] < height[right]) {
                if(height[left] > maxLeft) {
                    maxLeft = height[left];
                }
                sums += maxLeft - height[left];
                left++;
            } else {
                if(height[right] > maxRight) {
                    maxRight = height[right];
                }
                sums += maxRight - height[right];
                right--;
            }
        }
        return sums;
    }
};

