//
//  73 Set Matrix Zeroes.cpp
//  leetcode
//
//  Created by william wei on 18/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        for (int i=0; i<matrix.size(); i++) {
            col0 = ((matrix[i][0] == 0) ?0:col0);
            for (int j=1; j< matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i=matrix.size()-1; i>=0; i--) {
            for (int j=matrix[i].size()-1; j>=1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            if (!col0) matrix[i][0] = 0;
        }
    }
};
