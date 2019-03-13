//
//  91 Decode Ways.cpp
//  leetcode
//
//  Created by william wei on 2019/3/12.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        int *N = new int[s.length()];
        for(int i=0; i<s.length(); i++) {
            if (s[i] == '0' && (i == 0 || !((s[i-1] == '1') || s[i-1] == '2'))) {
                return 0;
            }
        }
        N[0] = 1;
        if (s.length() == 1) return N[0];
        N[1] = (s[0] == '2' && s[1] <= '6' && s[1] != '0') || (s[0] == '1' && s[1] != '0' ) ? 2: 1;
        
        
        for (int i=2; i<s.length(); i++) {
            if (s[i] == '0') {
                N[i] = N[i-2];
            } else if ((s[i-1] == '2'  && s[i] <= '6') || (s[i-1] == '1')) {
                N[i] = N[i-2] + N[i-1];
            } else {
                N[i] = N[i-1];
            }
        }
        return N[s.length()-1];
    }
};

