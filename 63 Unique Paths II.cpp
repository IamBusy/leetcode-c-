//
//  63 Unique Paths II.cpp
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int *paths = new int[n];
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        paths[0] = 1;
        for (int i=1; i<n; i++) {
            paths[i] = obstacleGrid[0][i] == 1?0:paths[i-1];
        }
        for (int i=1; i<m; i++) {
            for (int j=0; j<n; j++) {
                paths[j] = obstacleGrid[i][j] == 1? 0 : (paths[j] + (j>0?paths[j-1]:0));
            }
        }
        return paths[n-1];
    }
};
