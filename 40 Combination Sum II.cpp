//
//  40 Combination Sum II.cpp
//  leetcode
//
//  Created by william wei on 07/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int minnum = -1;
    int length = -1;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(minnum == -1) {
            sort(candidates.begin(), candidates.end());
            minnum = candidates[0];
            length = candidates.size();
        }
        vector<vector<int>> res = vector<vector<int>>();
        if(target < minnum) {
            return res;
        } else {
            for (int i=0; i<candidates.size(); i++) {
                if(i>0 && candidates[i] == candidates[i-1]) {
                    continue;
                }
                if(target > candidates[i]) {
                    vector<int> newCand = vector<int>(candidates.begin() + i + 1, candidates.end());
                    vector<vector<int>> rtn = combinationSum2(newCand, target - candidates[i]);
                    if(rtn.size() > 0) {
                        for (int j=rtn.size()-1; j>=0; j--) {
                            rtn[j].push_back(candidates[i]);
                            res.push_back(rtn[j]);
                        }
                    }
                } else if(target == candidates[i]) {
                    res.push_back(vector<int>(1,candidates[i]));
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

