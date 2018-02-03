//
//  55 Jump Game.cpp
//  leetcode
//
//  Created by william wei on 03/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int levelStart = 0, levelEnd = 1;
        int maxStep = 0;
        while (true) {
            for (int i=levelStart; i<levelEnd; i++) {
                if (i + nums[i] > maxStep) {
                    maxStep = i + nums[i];
                }
            }
            if (maxStep + 1 >= nums.size()) {
                return true;
            }
            if (levelEnd >= maxStep + 1) {
                return false;
            }
            levelStart = levelEnd;
            levelEnd = maxStep + 1;
        }
    }
};
