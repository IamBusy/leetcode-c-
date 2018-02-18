//
//  72 Edit Distance.cpp
//  leetcode
//
//  Created by william wei on 07/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
    int triMin(int a, int b, int c) {
        if(a<b) {
            return (a<c? a: c);
        } else {
            return (b<c? b: c);
        }
    }
public:
    /**
     * A[i][j] = A[i-1][j-1]                                   when s[i] == s[j]
     *         = min(A[i][j-1], A[i-1][j], A[i-1][j-1]) + 1    when s[i] != s[j]
     *
     */
    int minDistance(string word1, string word2) {
        int**dis = new int*[word1.length()+1];
        dis[0] = new int[word2.length()+1];
        for (int i=0; i<=word2.length(); i++) {
            dis[0][i] = i;
        }
        for (int i=1; i <= word1.length(); i++) {
            dis[i] = new int[word2.length()+1];
            dis[i][0] = i;
            for (int j=1; j <= word2.length(); j++) {
                if (word1[i-1] == word2[j-1]) {
                    dis[i][j] = dis[i-1][j-1];
                } else {
                    dis[i][j] = triMin(dis[i-1][j-1], dis[i][j-1], dis[i-1][j]) + 1;
                }
            }
        }
        return dis[word1.length()][word2.length()];
    }
};
