//
//  33 Search in Rotated Sorted Array.cpp
//  leetcode
//
//  Created by william wei on 25/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = nums.size();
        if(cnt == 0) return -1;
        bool isStart = true;
        bool isSeq  = false;
        if(target<nums[0]) {
            isStart = false;
        }
        if(nums[0]<nums[cnt-1]) {
            isSeq = true;
        }
        int low = 0, high = cnt-1;
        while (low < high-1) {
            int mid = (low+high)/2;
            if(isSeq) {
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    low = mid;
                } else {
                    high = mid;
                }
                continue;
            }
            if(isStart) {
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    if(nums[mid] > nums[0]) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                } else {
                    high = mid;
                    isSeq = true;
                }
            } else {
                if(nums[mid] == target) {
                    return mid;
                } else if(nums[mid] < target) {
                    low = mid;
                    isSeq = true;
                } else {
                    if(nums[mid] > nums[0]) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
            }
        }
        if(nums[low] == target) {
            return  low;
        } else if(nums[high] == target){
            return high;
        } else {
            return -1;
        }
    }
};

