//
//  77 Combinations.cpp
//  leetcode
//
//  Created by william wei on 2018/11/29.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    bool add(int*index, int n, int k) {
        int cur = k - 1;
        bool continued = true;
        index[cur]++;
        while (cur > 0 && index[cur] > (n-(k-cur) + 1) ){
            index[--cur]++;
        }
        if (cur == 0 && index[0] == n- k + 1) {
            continued = false;
        }
        for (int i = cur + 1; i<k; i++) {
            index[i] = index[i-1] + 1;
        }
        return continued;
    }
    vector<vector<int>> combine(int n, int k) {
        int *index = new int[k];
        for (int i=0; i< k; i++) {
            index[i] = i+1;
        }
        vector<vector<int>> res = vector<vector<int>>{vector<int>(index, index + k)};
        if (n == k) {
            return res;
        }
        while (add(index, n, k)) {
            res.push_back(vector<int>(index, index + k));
        }
        res.push_back(vector<int>(index, index + k));
        return res;
    }
};
