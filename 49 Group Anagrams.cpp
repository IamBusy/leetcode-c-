//
//  49 Group Anagrams.cpp
//  leetcode
//
//  Created by william wei on 29/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,int> keys = map<string,int>();
        vector<vector<string>> res = vector<vector<string>>();
        for (int i=strs.size() - 1; i>=0; i--) {
            string str = strs[i];
            sort(str.begin(), str.end());
            auto iter = keys.find(str);
            if (iter != keys.end()) {
                res[iter->second].push_back(strs[i]);
            } else {
                keys[str] = res.size();
                res.push_back(vector<string>(1, strs[i]));
            }
        }
        return res;
    }
};

