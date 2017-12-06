//
//  36 Valid Sudoku.cpp
//  leetcode
//
//  Created by william wei on 06/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int boardSize = 9;
        const char MARK = '.';
        int rows[boardSize][boardSize] = {0};
        int columns[boardSize][boardSize] = {0};
        int blocks[boardSize][boardSize] = {0};
        for (int i=0; i<boardSize; i++) {
            for (int j=0; j<boardSize; j++) {
                if(board[i][j] != MARK) {
                    int num = board[i][j] - '1';
                    if(rows[i][num] != 0) {
                        return false;
                    }
                    rows[i][num]++;
                    if(columns[j][num] != 0) {
                        return false;
                    }
                    columns[j][num]++;
                    
                    if(blocks[i/3 * 3+j/3][num] != 0) {
                        return false;
                    }
                    blocks[i/3 * 3+j/3][num] ++;
                }
            }
        }
        return true;
    }
};

