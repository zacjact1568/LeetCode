//
// Created by Zack Zhang on 2018/5/2.
//

#ifndef LEETCODE_TWOSUM_H
#define LEETCODE_TWOSUM_H

#include <vector>

using namespace std;

class TwoSum {

private:

    vector<int> solution(vector<int> &nums, int target);

    vector<int> recommended(vector<int> &nums, int target);

public:

    static void test();
};

#endif //LEETCODE_TWOSUM_H
