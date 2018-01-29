//
//  50 Pow(x, n).cpp
//  leetcode
//
//  Created by william wei on 29/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if(n < 0) {
            return 1 / (myPow(x, -(n + 1)) * x);
        } else {
            return n % 2 == 0? myPow(x * x, n/2): x * myPow(x * x, (n - 1)/2);
        }
    }
};
