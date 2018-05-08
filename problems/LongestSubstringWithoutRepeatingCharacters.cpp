//
// Created by Zack Zhang on 2018/5/8.
//

#include "LongestSubstringWithoutRepeatingCharacters.h"

#include <unordered_map>

int LongestSubstringWithoutRepeatingCharacters::solution(string s) {
    int len = 0;
    string substring;
    for (char ch : s) {
        auto repeatPos = substring.find(ch);
        if (repeatPos != string::npos) substring.erase(0, repeatPos + 1);
        substring += ch;
        auto newLen = (int) substring.size();
        if (newLen > len) len = newLen;
    }
    return len;
}

int LongestSubstringWithoutRepeatingCharacters::recommended(string s) {
    int len = 0;
    // A hash map, in which the key is the character in substring, the value is the position of the character in the string "s"
    // The position is start from 1 but not 0
    unordered_map<char, int> char2Pos;
    // "i" and "j" is the start and end index of the substring respectively
    // The index is start from 0
    for (int j = 0, i = 0; j < s.size(); ++j) {
        char ch = s[j];
        if (char2Pos.count(ch)) {
            // If the key exists, which means character "ch" exists in the substring
            int& pos = char2Pos.at(ch);
            // The new "i" should ensure that there's no repeating characters in the substring
            // So, if "pos" is less than or equal to "i", which means "ch" doesn't exist in the substring, there's no need to update "i"
            // And if "pos" is greater than "i", which means "ch" exists in the substring, "i" should be the next index of "pos"
            i = max(pos, i);
            // Update the corresponding value "pos" of key "ch" in the map
            pos = j + 1;
        } else {
            // If the key doesn't exist, which means character "ch" doesn't exist in the substring
            // Insert the character-position pair into the map
            char2Pos.insert(make_pair(ch, j + 1));
        }
        // Update the new "len", only if the new substring is longer than the old one
        len = max(len, j - i + 1);
    }
    return len;
}

void LongestSubstringWithoutRepeatingCharacters::test() {
    LongestSubstringWithoutRepeatingCharacters longestSubstringWithoutRepeatingCharacters;
    longestSubstringWithoutRepeatingCharacters.solution("abcabcbb");
}
