//
//  79 Word Search.cpp
//  leetcode
//
//  Created by william wei on 2019/1/5.
//  Copyright © 2019 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool findAt(vector<vector<char>>& board, int row, int col, string word, int idx, int *used) {
        if (idx >= word.length()) {
            return true;
        }
        bool found = false;
        // up
        if (row > 0 && board[row-1][col] == word[idx] && used[(row-1) * board[0].size() + col] == 0) {
            used[(row-1)*board[0].size() + col] = 1;
            found = findAt(board, row-1, col, word, idx+1, used);
            if (found) {
                return true;
            }
            used[(row-1)*board[0].size() + col] = 0;
        }
        // down
        if (row+1<board.size() && board[row+1][col] == word[idx] && used[(row+1)*board[0].size() + col] == 0) {
            used[(row+1)*board[0].size() + col] = 1;
            found = findAt(board, row+1, col, word, idx+1, used);
            if (found) {
                return true;
            }
            used[(row+1)*board[0].size() + col] = 0;
        }
        //left
        if (col > 0 && board[row][col-1] == word[idx] && used[row * board[0].size() + col - 1] == 0) {
            used[row * board[0].size() + col - 1] = 1;
            found = findAt(board, row, col-1, word, idx+1, used);
            if (found) {
                return true;
            }
            used[row * board[0].size() + col - 1] = 0;
        }
        // right
        if (col+1 < board[0].size() && board[row][col+1] == word[idx]
            && used[row*board[0].size() + col + 1] == 0) {
            used[row*board[0].size() + col + 1] = 1;
            found = findAt(board, row, col+1, word, idx+1, used);
            if (found) {
                return true;
            }
            used[row*board[0].size() + col + 1] = 0;
        }
        return false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int *used = new int[board.size()*board[0].size()];
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    memset(used, 0, board.size()*board[0].size()*sizeof(int));
                    used[i*board[0].size()+j] = 1;
                    if (findAt(board, i, j, word, 1, used)) {
                        return true;
                    }
                }
            }
        }
        delete []used;
        return false;
    }
};


