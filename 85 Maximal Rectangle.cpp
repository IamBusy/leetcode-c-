//
//  85 Maximal Rectangle.cpp
//  leetcode
//
//  Created by william wei on 2019/2/9.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        //int *heights = new int[matrix[0].size()];
        vector<int> heights = vector<int>(matrix[0].size(), 0);
        int maxArea = 0;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> s;
        int maxArea = 0;
        for (int i=0; i<heights.size(); i++) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
            } else {
                int idx = s.top();
                s.pop();
                maxArea = max(maxArea, heights[idx] * (s.empty()? i: (i - s.top() - 1)));
                --i;
            }
        }
        return maxArea;
    }
};
