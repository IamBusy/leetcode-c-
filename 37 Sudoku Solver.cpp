//
//  37 Sudoku Solver.cpp
//  leetcode
//
//  Created by william wei on 07/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    const static int boardSize = 9;
    const static char MARK = '.';
    int rows[boardSize][boardSize] = {0};
    int columns[boardSize][boardSize] = {0};
    int blocks[boardSize][boardSize] = {0};
    
public:
    bool solve(vector<vector<char>>& board, int i, int j) {
        for (; i<boardSize; i++) {
            for (; j<boardSize; j++) {
                if(board[i][j] == MARK) {
                    for (int k = 0; k<boardSize; k++) {
                        if(rows[i][k] == 0 && columns[j][k] == 0 && blocks[i/3*3 + j/3][k] == 0) {
                            rows[i][k] = 1;
                            columns[j][k] = 1;
                            blocks[i/3*3 + j/3][k] = 1;
                            board[i][j] = k + '1';
                            if(solve(board, i, j+1)) {
                                return true;
                            } else {
                                rows[i][k] = 0;
                                columns[j][k] = 0;
                                blocks[i/3*3 + j/3][k] = 0;
                            }
                        }
                    }
                    board[i][j] = MARK;
                    return false;
                }
            }
            j = 0;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int startI = -1, startJ = -1;
        for (int i=0; i<boardSize; i++) {
            for (int j=0; j<boardSize; j++) {
                if(board[i][j] != MARK) {
                    int num = board[i][j] - '1';
                    rows[i][num]++;
                    columns[j][num]++;
                    blocks[i/3 * 3+j/3][num] ++;
                } else if(startI == -1){
                    startI = i;
                    startJ = j;
                }
            }
        }
        solve(board, startI, startJ);
    }
};
