//
//  67 Add Binary.cpp
//  leetcode
//
//  Created by william wei on 05/02/2018.
//  Copyright © 2018 william wei. All rights reserved.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            swap(a, b);
        }
        int carry = 0;
        for (int i = 0; i<b.length(); i++) {
            int sum = carry + a[a.length()-1-i] - '0' + b[b.length()-1-i] - '0';
            carry = sum / 2;
            a[a.length()-1-i] = sum % 2;
        }
        for (int i= b.length(); i<a.length() && carry; i++) {
            int sum = a[a.length()-1-i] - '0' + carry;
            carry = sum/2;
            a[a.length()-1-i] == sum % 2;
        }
        if (carry) {
            a = char(carry + '0') + a;
        }
        return a;
    }
};
