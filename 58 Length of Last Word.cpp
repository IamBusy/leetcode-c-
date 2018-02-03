//
//  58 Length of Last Word.cpp
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
    int lengthOfLastWord(string s) {
        int length = 0;
        int i= s.length()-1;
        while (s[i] == ' ') {
            i--;
        }
        for (; i>=0; i--) {
            if (s[i] == ' ') {
                break;
            }
            length++;
        }
        return length;
    }
};
