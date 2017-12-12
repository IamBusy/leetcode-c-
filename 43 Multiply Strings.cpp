//
//  43 Multiply Strings.cpp
//  leetcode
//
//  Created by william wei on 08/12/2017.
//  Copyright © 2017 william wei. All rights reserved.
//
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.length() < num2.length()) {
            swap(num1, num2);
        }
        if(num2.length() == 1) {
            switch (num2[0]) {
                case '0':
                    return "0";
                    break;
                case '1':
                    return num1;
                    break;
                default:
                    string res = "";
                    int carry = 0;
                    int n = num2[0]-'0';
                    int tmp;
                    for (int i=num1.length()-1; i>=0; i--) {
                        tmp = carry + (n * (num1[i]-'0'));
                        carry = tmp/10;
                        res = char(tmp % 10+'0') + res;
                    }
                    if(carry > 0) {
                        res = char(carry + '0') + res;
                    }
                    return res;
            }
            
        } else {
            string* sums = new string[num2.length()];
            for (int i=num2.length()-1; i>=0; i--) {
                sums[num2.length()-1-i]= multiply(num1, num2.substr(i,1));
            }
            int totalLen = num1.length() + num2.length();
            int carry = 0;
            int tmp;
            string res = string(totalLen,'0');
            for (int i=0; i<totalLen; i++) {
                tmp = 0;
                for (int j=0; j <= i && j<num2.length(); j++) {
                    if(int(sums[j].length()-1 + j - i) >= 0 ) {
                        tmp +=( sums[j][sums[j].length()-1+j-i] - '0');
                    }
                }
                tmp+= carry;
                carry = tmp/10;
                res[totalLen-1-i] = char(tmp%10+'0');
            }
            int i = -1;
            while (res[i+1] == '0') {
                i++;
            }
            if(i >= 0) {
                res = res.substr(i+1,res.length());
            }
            delete []sums;
            return res;
        }
    }
};
