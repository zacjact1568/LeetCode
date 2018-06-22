//
// Created by Zack Zhang on 2018/6/21.
//

// Note: I can't find an algorithm which has a time complexity of O(log(m+n))
// Reference: https://zhuanlan.zhihu.com/p/33168674

#include "MedianOfTwoSortedArrays.h"

double MedianOfTwoSortedArrays::solution(vector<int> &nums1, vector<int> &nums2) {
    auto len = nums1.size() + nums2.size();
    double result;
    if (len % 2 == 0) {
        // The sum of the length of two arrays is even
        // The median is the mean of the (len/2)th smallest number and the (len/2+1)th smallest number
        result = (findKthSmallestNum(nums1, 0, nums2, 0, (int) len / 2) + findKthSmallestNum(nums1, 0, nums2, 0, (int) len / 2 + 1)) / 2;
    } else {
        // The sum of the length of two arrays is odd
        // The median is the (len/2+1)th smallest number
        result = findKthSmallestNum(nums1, 0, nums2, 0, (int) len / 2 + 1);
    }
    return result;
}

// Find the kth smallest number in residual nums1 and nums2
// Note: "residual" means the array should start from "start*" of "nums*"
double MedianOfTwoSortedArrays::findKthSmallestNum(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k) {
    auto len1 = nums1.size();
    auto len2 = nums2.size();
    if (start1 >= len1) {
        // There are no numbers in residual nums1, the kth smallest number must be in residual nums2
        // So return the kth number of residual nums2 (which has already ordered)
        return nums2[start2 + k - 1];
    }
    if (start2 >= len2) {
        return nums1[start1 + k - 1];
    }

    if (k == 1) {
        // The smallest number of residual nums1 and nums2
        // Only need to compare two first numbers of two residual arrays
        return min(nums1[start1], nums2[start2]);
    }

    // The index of (k/2)th number of each residual array
    int index1 = start1 + k / 2 - 1;
    int index2 = start2 + k / 2 - 1;
    // The (k/2)th number of each residual array
    int num1, num2;
    if (index1 < len1) {
        num1 = nums1[index1];
    } else {
        // The length of residual nums1 is less than the index of (k/2)th number
        // So the kth smallest number can't be in the first k/2 numbers of residual nums2, so "delete" them
        // Deleted numbers is smaller than the kth smallest number
        // That is to say, the new residual nums2 should start from start2 + k/2
        // Just need to find the (k - k/2)th smallest number of two new residual arrays
        return findKthSmallestNum(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
    if (index2 < len2) {
        num2 = nums2[index2];
    } else {
        return findKthSmallestNum(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    }
    // If the (k/2)th number of each array exists
    // Compare two (k/2)th number of two residual arrays
    // Find the smaller one, and "delete" the first k/2 numbers of corresponding residual array
    if (num1 < num2) {
        return findKthSmallestNum(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    } else {
        return findKthSmallestNum(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
}

void MedianOfTwoSortedArrays::test() {
    MedianOfTwoSortedArrays medianOfTwoSortedArrays;
    vector<int> nums1, nums2;
    // nums1: [2, 5, 8]
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(8);
    // nums2: [3, 6, 11, 15]
    nums2.push_back(3);
    nums2.push_back(6);
    nums2.push_back(11);
    nums2.push_back(15);
    // Expect output: 6
    medianOfTwoSortedArrays.solution(nums1, nums2);
}
