//
//  89 Gray Code.cpp
//  leetcode
//
//  Created by william wei on 2019/2/12.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    void utils(bitset<32> &bits, vector<int> &result, int n) {
        if (n == 0) {
            result.push_back(bits.to_ulong());
        } else {
            utils(bits, result, n-1);
            bits.flip(n-1);
            utils(bits, result, n-1);
        }
        
    }
    vector<int> grayCode(int n) {
        vector<int> result;
        bitset<32>bits;
        utils(bits, result, n);
        return result;
    }
};
