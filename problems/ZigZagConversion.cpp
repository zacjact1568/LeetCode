//
// Created by Zack Zhang on 2018/9/12.
//

#include "ZigZagConversion.h"

#include <vector>

string ZigZagConversion::solution(string s, int numRows) {
    auto rows = new vector<char>[numRows];
    int i = 0;
    bool forward = true;
    for (char ch : s) {
        rows[i].push_back(ch);
        if (numRows > 1) {
            if (i == 0) {
                forward = true;
            } else if (i == numRows - 1) {
                forward = false;
            }
            i = forward ? i + 1 : i - 1;
        }
    }
    auto sLen = s.size();
    auto result = new char[sLen + 1];
    int offset = 0;
    for (int j = 0; j < numRows; j++) {
        auto row = rows[j];
        auto rowLen = row.size();
        for (size_t k = 0; k < rowLen; k++) {
            result[k + offset] = row[k];
        }
        offset += rowLen;
    }
    delete[] rows;
    result[sLen] = '\0';
    return result;
}

void ZigZagConversion::test() {
    ZigZagConversion zigZagConversion;
    zigZagConversion.solution("PAYPALISHIRING", 3);
}
