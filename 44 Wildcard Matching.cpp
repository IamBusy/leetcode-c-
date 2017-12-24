//
//  44 Wildcard Matching.cpp
//  leetcode
//
//  Created by Wei,Xiaole on 23/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool **table = new bool*[s.length()+1];
        for (int i=0; i<=s.length(); i++) {
            table[i] = new bool[p.length()+1];
            table[i][0] = false;
        }
        table[0][0] = true;
        for (int i=1; i<=p.length(); i++) {
            if(p[i-1] == '*' && table[0][i-1]) {
                table[0][i] = true;
            } else {
                table[0][i] = false;
            }
        }
        bool rowFalse = true;
        for (int i=1; i<=s.length(); i++) {
            for (int j=1; j<=p.length(); j++) {
                if((table[i-1][j] && p[j-1] == '*') ||
                   (table[i][j-1] && p[j-1] == '*') ||
                   (table[i-1][j-1] && (p[j-1]=='*' || p[j-1] == '?' || s[i-1] == p[j-1]))
                   ){
                    table[i][j] = true;
                    rowFalse = false;
                } else {
                    table[i][j] = false;
                }
            }
            if(rowFalse) {
                table[s.length()][p.length()] = false;
                break;
            }
            rowFalse = true;
        }
        bool result = table[s.length()][p.length()];
        for (int i=0; i<=s.length(); i++) {
            delete []table[i];
        }
        delete []table;
        return result;
    }
};
