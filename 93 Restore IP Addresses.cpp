//
//  93 Restore IP Addresses.cpp
//  leetcode
//
//  Created by william wei on 2019/3/16.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void helper(string &s, int idx, int level, string cur, vector<string> &res) {
        if (level == 4) {
            if (idx == s.length()) {
                res.push_back(cur);
            }
        } else {
            if (cur.length() > 0) cur += ".";
            helper(s, idx+1, level+1, cur + string(1, s[idx]), res);
            if(idx < s.length() - 1 && s[idx] != '0') {
                helper(s, idx+2, level+1, cur+s.substr(idx, 2), res);
            }
            if(idx < s.length() - 2 && s.substr(idx, 3) <= "255" && s[idx] != '0' ) {
                helper(s, idx+3, level+1, cur+s.substr(idx, 3), res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) {
            return vector<string>{};
        }
        vector<string> res;
        helper(s, 0, 0, "", res);
        return res;
    }
};
