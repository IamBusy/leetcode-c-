//
//  87 Scramble String.cpp
//  leetcode
//
//  Created by william wei on 2019/2/12.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        } else if (s1.length() != s2.length()) {
            return false;
        }
        
        /**
         * 所包含各个charj应具有相同个数
         */
        int counter[128] = {0};
        for (int i = 0; i<s1.length(); i++) {
            counter[s1[i]]++;
            counter[s2[i]]--;
        }
        for (int i=0; i<128; i++) {
            if (counter[i] != 0) {
                return false;
            }
        }
        for (int i=1; i<s1.length(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i, s1.length()), s2.substr(i, s2.length())) ) {
                return true;
            }
            
            if (isScramble(s1.substr(0, i), s2.substr(s2.length()-i, s2.length())) &&
                isScramble(s1.substr(i, s1.length()), s2.substr(0, s2.length()-i))) {
                return true;
            }
        }
        return false;
    }
};

