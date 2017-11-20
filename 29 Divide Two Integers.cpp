//
//  29 Divide Two Integers.cpp
//  leetcode
//
//  Created by william wei on 08/10/2017.
//  Copyright © 2017 william wei. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int div(int dividend, int divisor, int maxMove) {
    while (maxMove > 0) {
        int afterMove = divisor << maxMove;
        if(afterMove > 0 && afterMove < dividend) {
            return maxMove;
        }
        maxMove--;
    }
    return 0;
}

int bitLen(int num) {
    if(num == INT_MIN) {
        return 32;
    }
    if(num < 0) {
        num = -num;
    }
    int len = 0;
    while ((num>>len)) {
        len++;
    }
    return len;
}

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            switch (divisor) {
                case -1:
                    return INT_MAX;
                    break;
                case 1:
                    return INT_MIN;
                    break;
                case -2:
                    return 1073741824;
                    break;
                case 2:
                    return -1073741824;
                    break;
                case INT_MIN:
                    return 1;
                case INT_MAX:
                    return -1;
                default:
                    dividend++;
                    break;
            }
        }
        
        bool neg = false;
        if((dividend<0 && divisor > 0) ||
           (dividend>0 && divisor < 0)) {
            neg = true;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        if(divisor > dividend || dividend == 0 || divisor < 0) {
            return 0;
        }
        int dividendBitLen = bitLen(dividend);
        int divisorBitLen = bitLen(divisor);
        int maxMove= dividendBitLen - divisorBitLen;
        
        int returnMoveNum = div(dividend,divisor,maxMove);
        int result = 0;
        while (true) {
            result += (1<<returnMoveNum);
            dividend = dividend - ( divisor<< returnMoveNum);
            if(dividend<divisor) {
                break;
            }
            returnMoveNum = div(dividend,divisor,maxMove);
        }
        if(neg) {
            result = -result;
        }
        return result;
    }
};
