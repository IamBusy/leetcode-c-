//
//  30 Substring with Concatenation of All Words.cpp
//  leetcode
//
//  Created by william wei on 24/11/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result = vector<int>();
        
        // Assert length of words > 0
        int wordsLen = words[0].length();
        int length = s.length();
        int findNum = 0;
        map<string,int> table = map<string,int>();
        map<string,int> currentTable = map<string, int>();
        map<string,int>::iterator iter;
        for (int i= words.size()-1; i>=0; i--) {
            if((iter = table.find(words[i])) == table.end()) {
                table.insert(pair<string, int>(words[i],1));
            } else {
                iter->second++;
            }
        }
        int i=0;
        string nextWord = "";
        while (i<length) {
            nextWord = s.substr(i,wordsLen);
            if(table.find(nextWord) != table.end()) {
                // Repeat or invalid
                map<string,int>::iterator iter = currentTable.find(nextWord);
                if(iter != currentTable.end() && iter->second >= table[nextWord]) {
                    i -= (findNum*wordsLen-1);
                    currentTable.clear();
                    findNum = 0;
                } else {    // Find and valid
                    if(iter == currentTable.end()) {
                        currentTable.insert(pair<string, int>(nextWord,1));
                    } else {
                        iter->second++;
                    }
                    
                    findNum++;
                    // All words occur once
                    if(findNum == words.size()) {
                        result.push_back(i-(findNum-1)*wordsLen);
                        i -= ((findNum)*wordsLen-1);
                        currentTable.clear();
                        findNum = 0;
                        //i-=wordsLen;
                    }
                    i+= wordsLen;
                }
                
            } else {
                i -= (currentTable.size()*wordsLen-1);
                //i++;
                currentTable.clear();
                findNum = 0;
            }
        }
        return result;
    }
};
