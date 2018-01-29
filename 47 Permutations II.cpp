//
//  47 Permutations II.cpp
//  leetcode
//
//  Created by william wei on 28/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res = vector<vector<int>>();
        recursive(nums, 0, res);
        return res;
    }
    
    void recursive(vector<int> &nums, int start, vector<vector<int>> &res) {
        if (start >= nums.size()) {
            res.push_back(nums);
        } else {
            set<int> used = set<int>();
            for (int i=start; i< nums.size(); i++) {
                if ((i > start && nums[i] == nums[start]) || used.find(nums[i]) != used.end()) {
                    continue;
                }
                used.insert(nums[i]);
                swap(nums[i], nums[start]);
                recursive(nums, start+1, res);
                swap(nums[i], nums[start]);
            }
        }
    }
};
