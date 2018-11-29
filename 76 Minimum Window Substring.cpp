//
//  76 Minimum Window Substring.cpp
//  leetcode
//
//  Created by william wei on 2018/10/14.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        if (s == "" || t == "") {
            return "";
        }
        vector<int> map = vector<int>(128, 0);
        vector<int> exists = vector<int>(128, 0);
        int begin = 0, cur = 0, num = t.size();
        int minWinLen = INT_MAX, minWinStart = 0;
        s = s + " ";
        for (auto c:t) {
            map[c]++;
            exists[c] = 1;
        }
        while (cur < s.size()) {
            map[s[cur]]--;
            if (map[s[cur]] >= 0) {
                num--;
            }
            // find a valid window
            while (num == 0) {
                if (cur - begin < minWinLen) {
                    minWinLen = cur - begin;
                    minWinStart = begin;
                }
                map[s[begin]]++;
                if (map[s[begin]] > 0) {
                    num++;
                }
                begin++;
            }
            cur++;
        }
        if (minWinLen <= s.size()) {
            return s.substr(minWinStart, minWinLen + 1);
        }
        return "";
    }
};

