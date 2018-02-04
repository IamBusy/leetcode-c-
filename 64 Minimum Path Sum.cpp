//
//  64 Minimum Path Sum.cpp
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int *paths = new int[n];
        for (int i=0; i<n; i++) {
            paths[i] = (i>0?paths[i-1]:0) + grid[0][i];
        }
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                paths[j] = min(i>0?paths[j]:INT_MAX, j>0?paths[j-1]:INT_MAX) + grid[i][j];
            }
        }
        return paths[n-1];
    }
};

