//
//  56 Merge Intervals.cpp
//  leetcode
//
//  Created by william wei on 03/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res = vector<Interval>();
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](Interval&a, Interval&b){ return a.start < b.start;});
        int lastIdx = 0;
        int lastEnd = intervals[0].end;
        for (int i=1; i< intervals.size(); i++) {
            if (intervals[i].start > lastEnd) {
                res.push_back(Interval(intervals[lastIdx].start, lastEnd));
                lastIdx = i;
                lastEnd = intervals[i].end;
            } else if(intervals[i].end > lastEnd){
                lastEnd = intervals[i].end;
            }
        }
        res.push_back(Interval(intervals[lastIdx].start, lastEnd));
        return res;
    }
};

