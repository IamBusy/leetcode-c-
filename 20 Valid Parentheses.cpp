//
//  20 Valid Parentheses.cpp
//  leetcode
//
//  Created by william wei on 13/09/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i=0; i<s.length(); i++) {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
                st.push(s[i]);
                continue;
            }
            if (s[i] == '}' ){
                if(st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
                continue;
            } else if (s[i] == ']') {
                if(st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
                continue;
            } else if (s[i] == ')'){
                if(st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
                continue;
            }
        }
        return st.empty();
    }
};
