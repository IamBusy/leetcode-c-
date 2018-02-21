//
//  74 Search a 2D Matrix.cpp
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int rowNum = matrix.size();
        int colNum = matrix[0].size();
        int low = 0, high = rowNum * colNum - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (matrix[mid/colNum][mid%colNum] == target) {
                return true;
            } else if (matrix[mid/colNum][mid%colNum] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return matrix[low/colNum][low%colNum] == target;
    }
};
