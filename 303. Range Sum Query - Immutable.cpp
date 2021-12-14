// ***
//
// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
//
// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.
//
// ***

// Just remember the idea, don't worry too much about the index.
// prefixSum[0] is the sum when there's no element (i.e. 0).
// prefixSum[i+1] represents total sum from nums[0] to nums[i] (inclusive).
class NumArray {
public:
    NumArray(const vector<int>& nums) {
        prefixSum.resize(nums.size() + 1, 0);

        for (int i = 1; i <= nums.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) { return prefixSum[j + 1] - prefixSum[i]; }

private:
    vector<int> prefixSum;
};
