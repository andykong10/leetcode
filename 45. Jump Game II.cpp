// ***
//
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to
// the last index.
//
// Note: You can assume that you can always reach the last index.
//
// ***

int jump(vector<int>& nums) {
    // The ending index of current window. Initial window is [0, 0] so when i = 0 you initiate a jump.
    // You can jump to every index in this window in the same number of step from previous window.
    int curWindowEnd = 0;

    // The farthest index we can jump from current window,
    // this will be used to update curWindowEnd when we've reached the end of current window.
    int curMaxReach = 0;

    int totalJump = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        // Note that the problem guarantees that that we are can always jump to the last index.
        // Therefore no need to check if we can jump to current index.
        curMaxReach = max(curMaxReach, i + nums[i]);

        // If we've reached the end of current window, this will trigger another jump from current window, and our new
        // window's end (i.e. new curWindowEnd) will be curMaxReach. Why we have ;i<nums.size()-1;? Because if
        // we had ;i<nums.size();, we were including the last index, then another jump is triggered at last index, and
        // our totalJump will be 1 greater than what it should have been.
        if (i == curWindowEnd) {
            ++totalJump;
            curWindowEnd = curMaxReach;
        }
    }

    return totalJump;
}
