//
//  60 Permutation Sequence.cpp
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
    string getPermutation(int n, int k) {
        k--;
        string board(n, '0');
        string res;
        int* fract = new int[n+1];
        fract[0] = 1;
        for (int i=1; i<=n; i++) {
            fract[i] = fract[i-1] * i;
            board[i-1] = i;
        }
        for (int i=0; i<n; i++) {
            int t = k / fract[n-1-i];
            res += board[t];
            board.erase(t,1);
            k = k % fract[n-1-i];
        }
        return res;
    }
};

