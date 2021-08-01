// ***
//
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique
// triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
// ***
//
// The question asks you whether three number can form a target. In this question specifically, that target is 0.
//
// See also 167. Two Sum II - Input array is sorted.
// Read. 18. 4Sum first to see the general way of solving these problems.
// This is a generalization of that problem with an added for loop. The most important thing in this question
// is to eliminate possibly duplicate result.
//
// The solution below can be solved for all three sum questions which target can be anything.
vector<vector<int>> threeSum(vector<int>& nums, int target) {
    vector<vector<int>> allPairs;

    sort(nums.begin(), nums.end());

    // the stop condition is i < nums.size() - 2 because you are trying to find 3 sum, so you must have at least 2
    // numbers to search from your current number nums[i].
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                allPairs.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    --right;
                }
                ++left;
                --right;
            } else if (sum < target) {
                ++left;
            } else if (sum > target) {
                --right;
            }
        }
    }

    return allPairs;
}

