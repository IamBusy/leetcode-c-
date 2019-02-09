//
//  84 Largest Rectangle in Histogram.cpp
//  leetcode
//
//  Created by william wei on 2019/2/6.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;



class Solution {
public:
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
        //        if (heights.size() == 0) {
        //            return 0;
        //        }
        //        int *minTable = new int[heights.size()];
        //        int maxArea = 0;
        //
        //        for (int i=0; i<heights.size(); i++) {
        //            minTable[i] = heights[i];
        //            maxArea = max(maxArea, heights[i]);
        //            for (int j=i-1; j>=0; j--) {
        //                minTable[j] = heights[j] < minTable[j+1]? heights[j]: minTable[j+1];
        //                maxArea = max(maxArea, minTable[j] * (i - j + 1));
        //            }
        //        }
        //        return maxArea;
    }
};
