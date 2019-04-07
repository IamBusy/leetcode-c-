//
//  97 Interleaving String.cpp
//  leetcode
//
//  Created by william wei on 2019/4/6.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

/*********************
 *   Version 4
 *time: O(n^2)
 *space: O(n)
 *********************/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        if (s1.length() < s2.length()) {
            swap(s1, s2);
        }
        bool *table = new bool[s2.length()+1];
        for (int i = 0; i<=s1.length(); i++) {
            for (int j=0; j<=s2.length(); j++) {
                if (i == 0) {
                    table[j] = s2.substr(0, j) == s3.substr(0, j);
                } else if(j == 0) {
                    table[j] = s1.substr(0, i) == s3.substr(0, i);
                } else {
                    table[j] = ((s3[i+j-1] == s1[i-1]) && table[j]) || (s3[i+j-1] == s2[j-1] && table[j-1]);
                }
            }
        }
        return table[s2.length()];
    }
};


/*********************
 *   Version 3
 *time: O(n^2)
 *space: O(n^2)
 *********************/
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        bool **table = new bool*[s1.length()+1];
//
//        for (int i = 0; i<=s1.length(); i++) {
//            table[i] = new bool[s2.length()+1];
//            for (int j=0; j<=s2.length(); j++) {
//                if (i == 0) {
//                    table[i][j] = s2.substr(0, j) == s3.substr(0, j);
//                } else if(j == 0) {
//                    table[i][j] = s1.substr(0, i) == s3.substr(0, i);
//                } else {
//                    table[i][j] = ((s3[i+j-1] == s1[i-1]) && table[i-1][j]) || (s3[i+j-1] == s2[j-1] && table[i][j-1]);
//                }
//            }
//        }
//        return table[s1.length()][s2.length()];
//    }
//};



/*********************
 *   Version 2
 *********************/
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        int **table = new int*[s1.length()+1];
//        for (int i=0; i<=s1.length(); i++) {
//            table[i] = new int[s2.length()+1];
//            memset(table[i], 0, sizeof(int) * (s2.length()+1));
//            table[i][0] = s1.substr(0, i) == s3.substr(0, i)? 1: 0;
//        }
//        for (int i=1; i<=s2.length(); i++) {
//            table[0][i] = s2.substr(0, i) == s3.substr(0, i)? 1: 0;
//        }
//        for (int i=1; i<=s1.length(); i++) {
//            for (int j=1; j<=s2.length(); j++) {
//                if (s3[i+j-1] == s1[i-1]) {
//                    table[i][j] = table[i-1][j];
//                    if (!table[i][j] && s3[i+j-1] == s2[j-1]) {
//                        table[i][j] = table[i][j-1];
//                    }
//                } else if(s3[i+j-1] == s2[j-1]) {
//                    table[i][j] = table[i][j-1];
//                } else {
//                    table[i][j] = 0;
//                }
//            }
//        }
//        return table[s1.length()][s2.length()];
//    }
//};

/*********************
 *   Version 1
 *********************/
 

//
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        if (s1.length() + s2.length() != s3.length()) {
//            return false;
//        }
//        if (s1.length() == 0) {
//            return s2 == s3;
//        } else if (s2.length() == 0) {
//            return s1 == s3;
//        } else {
//            if (s3[s3.length()-1] == s1[s1.length()-1]) {
//                bool isOk = isInterleave(s1.substr(0, s1.length()-1), s2, s3.substr(0, s3.length()-1));
//                if ((!isOk) && s3[s3.length()-1] == s2[s2.length()-1]) {
//                    isOk = isInterleave(s1, s2.substr(0, s2.length()-1), s3.substr(0, s3.length()-1));
//                }
//                return isOk;
//            } else if (s3[s3.length()-1] == s2[s2.length()-1]) {
//                return isInterleave(s1, s2.substr(0, s2.length()-1), s3.substr(0, s3.length()-1));
//            } else {
//                return false;
//            }
//        }
//    }
//};
