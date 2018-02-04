//
//  62 Unique Paths.cpp
//  leetcode
//
//  Created by william wei on 04/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int **paths = new int*[m];
        for (int i=0; i<m; i++) {
            paths[i] = new int[n];
            paths[i][0] = 1;
        }
        for (int i=0; i<n; i++) {
            paths[0][i] = 1;
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                paths[i][j] = paths[i][j-1] + paths[i-1][j];
            }
        }
        return paths[m-1][n-1];
    }
};

