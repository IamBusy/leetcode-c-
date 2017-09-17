//
//  22 Generate Parentheses.cpp
//  leetcode
//
//  Created by william wei on 17/09/2017.
//  Copyright © 2017 william wei. All rights reserved.
//
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n==0) {
            return vector<string>();
        }
        vector<string> res = vector<string>(1,"(");
        vector<int> left = vector<int>(1,1);
        vector<int> right = vector<int>(1,0);
        for (int i = 0; i< (n<<1); i++) {
            int num = res.size();
            for (int j=0; j<num; j++) {
                if(n - left[j] > 0 && n-right[j] > 0) {
                    if(left[j] > right[j]) {
                        res.push_back(res[j]+")");
                        left.push_back(left[j]);
                        right.push_back(right[j]+1);
                    }
                    res[j] = res[j] + "(";
                    left[j]++;
                    
                } else if(n - left[j] > 0) {
                    res[j] = res[j] + "(";
                    left[j]++;
                } else if (n - right[j] > 0) {
                    res[j] = res[j] + ")";
                    right[j]++;
                }
            }
        }
        return res;
    }
};
