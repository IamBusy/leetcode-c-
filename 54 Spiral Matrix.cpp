//
//  54 Spiral Matrix.cpp
//  leetcode
//
//  Created by william wei on 02/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res = vector<int>();
        int i=0, j=0, m=matrix.size(), n=m>0?matrix[0].size():0;
        while (i<m && j<n) {
            // top
            for (int k=j; k<n; k++) {
                res.push_back(matrix[i][k]);
            }
            i++;
            // right
            if (i<m) {
                for (int k=i; k<m; k++) {
                    res.push_back(matrix[k][n-1]);
                }
                n--;
            }
            // bottom
            if (i<m && j<n) {
                for (int k=n-1; k>=j; k--) {
                    res.push_back(matrix[m-1][k]);
                }
                m--;
            }
            // left
            if (i<m && j<n) {
                for (int k=m-1; k>=i; k--) {
                    res.push_back(matrix[k][j]);
                }
                j++;
            }
        }
        return res;
    }
};
