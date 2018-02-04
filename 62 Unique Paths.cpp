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
        int *paths = new int[n];
        for (int i=0; i<n; i++) {
            paths[i] = 1;
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                paths[j] = paths[j-1] + paths[j];
            }
        }
        return paths[n-1];
    }
};

