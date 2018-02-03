//
//  57 Insert Interval.cpp
//  leetcode
//
//  Created by william wei on 03/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>res;
        int i=0;
        bool inserted = false;
        for (; i< intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
            } else if(intervals[i].start <= newInterval.end) {
                newInterval.end = max(newInterval.end, intervals[i].end);
                newInterval.start = min(newInterval.start, intervals[i].start);
            } else {
                if (! inserted) {
                    res.push_back(newInterval);
                    inserted = true;
                }
                res.push_back(intervals[i]);
            }
        }
        if (!inserted) {
            res.push_back(newInterval);
        }
        return res;
    }
};
