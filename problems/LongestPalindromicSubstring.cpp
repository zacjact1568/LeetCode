//
// Created by Zack Zhang on 2018/7/24.
//

#include "LongestPalindromicSubstring.h"

string LongestPalindromicSubstring::solution(string s) {
    // Use Brute-Force
    int start = 0, end = 0;
    int len = 0, maxLen = 0;
    bool isPalindromic = false;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            len = j - i + 1;
            if (len > maxLen) {
                for (int k = 0; k < len / 2; ++k) {
                    if (s[i + k] != s[j - k]) {
                        isPalindromic = false;
                        break;
                    } else if (k == len / 2 - 1) {
                        isPalindromic = true;
                    }
                }
                if (isPalindromic || len == 1) {
                    maxLen = len;
                    start = i;
                    end = j;
                }
            }
        }
    }
    return s.substr((unsigned long) start, (unsigned long) end - start + 1);
}

string LongestPalindromicSubstring::recommended(string s) {
    // Use Dynamic Programming
    auto total = s.size();
    bool isPalindromic[total][total];
    int start = 0, end = 0, len = 0, maxLen = 0;
    for (int i = 0; i < total; ++i) {
        for (int j = 0; j <= i; ++j) {
            // Note: j is the start of the substring while i is the end
            if (j == i) {
                isPalindromic[j][i] = true;
            } else if (i - j == 1) {
                isPalindromic[j][i] = s[i] == s[j];
            } else if (i - j > 1) {
                isPalindromic[j][i] = s[i] == s[j] && isPalindromic[j + 1][i - 1];
            }
            len = i - j + 1;
            if (isPalindromic[j][i] && len > maxLen) {
                maxLen = len;
                start = j;
                end = i;
            }
        }
    }
    return s.substr((unsigned long) start, (unsigned long) end - start + 1);
}

void LongestPalindromicSubstring::test() {
    LongestPalindromicSubstring longestPalindromicSubstring;
    longestPalindromicSubstring.solution("babad");
}
