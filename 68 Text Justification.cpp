//
//  68 Text Justification.cpp
//  leetcode
//
//  Created by william wei on 05/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int len = 0, start = 0, i = 0, totalSpace = 0, deliSpace = 0;
        string line;
        for (; i<words.size(); i++) {
            // wordlen + wordnum-1 <= maxWidth
            if (len + words[i].length() + i - start > maxWidth) {
                totalSpace = maxWidth - len;
                for (int j=start; j<i; j++) {
                    deliSpace = i-1-j>0?ceil(1.0*totalSpace / (i-1-j)):totalSpace;
                    line += words[j] + string(deliSpace, ' ');
                    totalSpace -= deliSpace;
                }
                res.push_back(line);
                len = words[i].length();
                start = i;
                line = "";
            } else {
                len += words[i].length();
            }
        }
        line = words[start];
        for (int j=start + 1; j<i; j++) {
            line +=string(1, ' ') + words[j];
        }
        line += string(maxWidth-line.length(),' ');
        res.push_back(line);
        
        return res;
    }
};
