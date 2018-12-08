//
//  78 Subsets.cpp
//  leetcode
//
//  Created by william wei on 2018/12/8.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    void dfs(vector<int>&nums, int idx, vector<int>&out, vector<vector<int>>&result) {
        if (idx == nums.size() - 1) {
            result.push_back(out);
            out.push_back(nums[idx]);
            result.push_back(out);
            out.pop_back();
        } else {
            dfs(nums, idx+1, out, result);
            out.push_back(nums[idx]);
            dfs(nums, idx+1, out, result);
            out.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>out = vector<int>();
        vector<vector<int>> result = vector<vector<int>>();
        dfs(nums, 0, out, result);
        return result;
    }
};
