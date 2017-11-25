//
//  32 Longest Valid Parentheses.cpp
//  leetcode
//
//  Created by william wei on 25/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st = stack<int>();
        const int LEFT = -2;
        const int RIGHT = -1;
        for (int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(LEFT);
            } else if(!st.empty()){
                if(st.top() == LEFT) {
                    int num = 2;
                    st.pop();
                    if((!st.empty()) && st.top() > 0) {
                        num += st.top();
                        st.pop();
                    }
                    st.push(num);
                } else if(st.top() > 0) {
                    int lastNum = st.top();
                    bool rePush = true;
                    st.pop();
                    if((!st.empty()) && st.top() == LEFT) {
                        rePush = false;
                        st.pop();
                        lastNum+=2;
                        if((!st.empty()) && st.top() > 0) {
                            lastNum += st.top();
                            st.pop();
                        }
                    }
                    st.push(lastNum);
                    if(rePush) {
                        st.push(RIGHT);
                    }
                }
            } else {
                st.push(RIGHT);
            }
        }
        int res = 0;
        while (!st.empty()) {
            if(st.top() > res) {
                res = st.top();
            }
            st.pop();
        }
        return res;
    }
};

