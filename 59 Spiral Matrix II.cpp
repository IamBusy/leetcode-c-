//
//  59 Spiral Matrix II.cpp
//  leetcode
//
//  Created by william wei on 04/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> row = vector<int>(n, 0);
        vector<vector<int>> matrix;
        for (int i=0; i<n; i++) {
            matrix.push_back(row);
        }
        
        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int> nums = {n, n-1};
        int dir = 0;
        int rowIdx = 0, colIdx = -1;
        int index = 1;
        while (nums[dir%2] > 0) {
            for (int i=0; i<nums[dir%2]; i++) {
                rowIdx += directions[dir][0];
                colIdx += directions[dir][1];
                matrix[rowIdx][colIdx] = index++;
            }
            nums[dir%2]--;
            dir = (dir + 1) % 4;
        }
        return matrix;
    }
};
