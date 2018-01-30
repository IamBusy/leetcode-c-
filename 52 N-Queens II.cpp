//
//  52 N-Queens II.cpp
//  leetcode
//
//  Created by william wei on 30/01/2018.
//  Copyright © 2018 william wei. All rights reserved.
//


#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void search(int&res, vector<string> &board, int rowNum, int n) {
        for (int i=0; i<n; i++) {
            board[rowNum][i] = 'Q';
            bool valid = true;
            for (int j=0; j<rowNum; j++) {
                if (board[j][i] == 'Q') {
                    valid = false;
                    break;
                }
                if (i-(rowNum-j)>=0 && board[j][i-(rowNum-j)] == 'Q') {
                    valid = false;
                    break;
                }
                if (i+(rowNum-j)<n && board[j][i+(rowNum-j)] == 'Q') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (rowNum == n-1) {
                    res++;
                } else {
                    search(res, board, rowNum + 1, n);
                }
            }
            board[rowNum][i] = '.';
        }
    }
public:
    int totalNQueens(int n) {
        vector<string> board = vector<string>();
        int res = 0;
        string row = string(n, '.');
        for (int i=0; i<n; i++) {
            board.push_back(row);
        }
        search(res, board, 0, n);
        return res;
    }
};
