//
// Created by Zack Zhang on 2018/6/21.
//

#ifndef LEETCODE_MEDIANOFTWOSORTEDARRAYS_H
#define LEETCODE_MEDIANOFTWOSORTEDARRAYS_H

#include <vector>

using namespace std;

class MedianOfTwoSortedArrays {

private:

    double solution(vector<int>& nums1, vector<int>& nums2);

    double findKthSmallestNum(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k);

public:

    static void test();
};

#endif //LEETCODE_MEDIANOFTWOSORTEDARRAYS_H
