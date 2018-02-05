//
//  66 Plus One.cpp
//  leetcode
//
//  Created by william wei on 05/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow = 1;
        for (int i=digits.size()-1; i>=0; i--) {
            if (overflow) {
                int of = (digits[i] + overflow) / 10;
                digits[i] = (digits[i] + overflow) % 10;
                overflow = of;
            } else {
                break;
            }
        }
        if (overflow) {
            digits.insert(digits.begin(), overflow);
        }
        return digits;
    }
};
