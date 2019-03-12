//
//  90 Subsets II.cpp
//  leetcode
//
//  Created by william wei on 2019/2/20.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void search(vector<int>& nums, int idx, vector<vector<int>> &results, vector<int> &cur) {
        if (idx >=  nums.size()) {
            results.push_back(cur);
            return;
        }
        int dupNum = 0;
        int i = idx;
        while (i< nums.size() && nums[i++] == nums[idx]) {
            dupNum++;
        }
        vector<int> next = vector<int>(cur);
        search(nums, dupNum + idx, results, next);
        for (int i=0; i<dupNum; i++) {
            next.push_back(nums[idx]);
            search(nums, dupNum + idx, results, next);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>results = {};
        vector<int> tmp = {};
        search(nums, 0, results, tmp);
        return results;
    }
};
