//
//  34 Search for a Range.cpp
//  leetcode
//
//  Created by william wei on 26/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, cnt = nums.size(), high = cnt-1;
        int mid;
        vector<int> res = vector<int>();
        if(high<0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        while (low < high) {
            mid = (low + high) / 2;
            if(nums[mid] == target) {
                break;
            } else if (nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        mid = (low + high) / 2;
        if(nums[mid] != target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else {
            int start = mid, end = mid;
            while (start >= 0 && nums[start] == target) {
                start--;
            }
            while (end <= cnt-1 && nums[end] == target) {
                end++;
            }
            res.push_back(start+1);
            res.push_back(end-1);
            return  res;
        }
    }
};
