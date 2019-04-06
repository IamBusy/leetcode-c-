//
//  96 Unique Binary Search Trees.cpp
//  leetcode
//
//  Created by william wei on 2019/4/6.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        int *table = new int[max(n+1, 2)];
        memset(table, 0, sizeof(int) * max(n+1, 2));
        table[0] = 0;
        table[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=1; j<=i; j++) {
                table[i] += max(table[j-1], 1) * max(table[i-j], 1);
            }
        }
        return table[n];
    }
};
