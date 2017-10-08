//
//  28 Implement strStr().cpp
//  leetcode
//
//  Created by william wei on 04/10/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

int *buildNext(string needle) {
    int len = needle.length();
    int *next =  new int[len];
    int t = next[0] = -1,i=0;
    while (i<len-1) {
        if(t < 0 || needle[t] == needle[i]) {
            t++;i++;
            next[i] = t;
        } else {
            t = next[t];
        }
    }
    return next;
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLen = needle.length();
        int haystackLen = haystack.length();
        int *next = buildNext(needle);
        int i=0,j=0;
        while (j<needleLen && i<haystackLen) {
            if(j<0 || needle[j] == haystack[i]) {
                i++; j++;
            } else {
                j = next[j];
            }
        }
        delete next;
        return j==needleLen?i-j:-1;
    }
};
