//
// Created by Zack Zhang on 2018/5/2.
//

#include "TwoSum.h"

#include <unordered_map>

vector<int> TwoSum::solution(vector<int> &nums, int target) {
    vector<int> indices;
    bool finished = false;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                indices.push_back(i);
                indices.push_back(j);
                finished = true;
                break;
            }
        }
        if (finished) break;
    }
    return indices;
}

vector<int> TwoSum::recommended(vector<int> &nums, int target) {
    vector<int> indices;
    // unordered_map is same as hash_map
    unordered_map<int, int> num2index;
    for (int i = 0; i < nums.size(); ++i) {
        // Look back to check if current element's complement already exists in the table
        int complement = target - nums[i];
        if (num2index.count(complement)) {
            // Exists: A solution is found, finish iterating.
            indices.push_back(num2index.at(complement));
            indices.push_back(i);
            break;
        }
        // Doesn't exist: Continue inserting elements into num2index
        num2index.insert(make_pair(nums[i], i));
    }
    return indices;
}

void TwoSum::test() {
    TwoSum twoSum;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    twoSum.solution(nums, 9);
}
