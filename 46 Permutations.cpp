//
//  46 Permutations.cpp
//  leetcode
//
//  Created by william wei on 28/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res = vector<vector<int>>();
        recursive(nums, 0, res);
        return res;
    }
    
    void recursive(vector<int> &nums, int start, vector<vector<int>> &res) {
        if (start >= nums.size()) {
            res.push_back(nums);
        } else {
            for (int i=start; i< nums.size(); i++) {
                swap(nums[i], nums[start]);
                recursive(nums, start+1, res);
                swap(nums[i], nums[start]);
            }
        }
    }
};

