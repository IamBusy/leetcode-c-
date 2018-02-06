//
//  71 Simplify Path.cpp
//  leetcode
//
//  Created by william wei on 06/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        int workDir = 0;
        string word, resStr;
        stringstream ss(path);
        while (getline(ss, word, '/')) {
            if (word == "..") {
                workDir>0?workDir--:0;
            } else if(word == "") {
                //workDir = 0;
            } else if (word != ".") {
                res.insert(res.begin() + workDir, word);
                workDir++;
            }
        }
        for (int i=0; i<workDir; i++) {
            resStr += "/" + res[i];
        }
        if (resStr.empty()) {
            resStr = "/";
        }
        return resStr;
    }
};
