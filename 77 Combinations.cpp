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
    void dfs(int n, int k, int level, int start, vector<int>&out, vector<vector<int>>&result) {
        for (int i = start; i<=n; i++) {
            out[level] = i;
            if (level == k-1) {
                result.push_back(out);
            } else {
                dfs(n, k, level+1, i+1, out, result);
            }
        }
        
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>out = vector<int>(k);
        vector<vector<int>>result = vector<vector<int>>();
        dfs(n, k, 0, 1, out, result);
        return result;
    }
};

//
//class Solution {
//public:
//    bool add(int*index, int n, int k) {
//        int cur = k - 1;
//        bool continued = true;
//        index[cur]++;
//        while (cur > 0 && index[cur] > (n-(k-cur) + 1) ){
//            index[--cur]++;
//        }
//        if (cur == 0 && index[0] == n- k + 1) {
//            continued = false;
//        }
//        for (int i = cur + 1; i<k; i++) {
//            index[i] = index[i-1] + 1;
//        }
//        return continued;
//    }
//    vector<vector<int>> combine(int n, int k) {
//        int *index = new int[k];
//        for (int i=0; i< k; i++) {
//            index[i] = i+1;
//        }
//        vector<vector<int>> res = vector<vector<int>>{vector<int>(index, index + k)};
//        if (n == k) {
//            return res;
//        }
//        while (add(index, n, k)) {
//            res.push_back(vector<int>(index, index + k));
//        }
//        res.push_back(vector<int>(index, index + k));
//        return res;
//    }
//};
