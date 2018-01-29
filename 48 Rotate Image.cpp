//
//  48 Rotate Image.cpp
//  leetcode
//
//  Created by william wei on 29/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = n/2;
        int col = n%2 == 0? n/2 : n/2 + 1;
        for (int i=0; i< row; i++) {
            for (int j=0; j<col; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1 - j][i];
                matrix[n-1 - j][i] = matrix[n-1 - i][n-1 - j];
                matrix[n-1 - i][n-1 - j] = matrix[j][n-1 - i];
                matrix[j][n-1 - i] = tmp;
            }
        }
    }
};
