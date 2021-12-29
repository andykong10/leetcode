// ***
//
// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
// Input: [10,2]
// Output: "210"
// Example 2:
//
// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.
//
// ***
//
// This is a good question that tests how you use custom comparator in sort
// The idea here is to implement a string comparator to decide
// which string should come first during concatenation.
// Because when you have 2 numbers (let's convert them into string), you'll face only 2 cases:
//
// For example:
//
// string s1 = "9";
// string s2 = "31";
//
// case1 = s1 + s2; // 931
// case2 = s2 + s1; // 319
// Apparently, case1 is greater than case2 in terms of value.
// So, we should always put s1 in front of s2.
//
// Note on comparator: Binary function that accepts two elements in the range as arguments,
// and returns a value convertible to bool.
// The value returned indicates whether the element passed as first argument should go before the second.
// In our case, obviously a needs to go before b if string version of a+b is greater than b+a.
// For example "9" + "5" > "5" + "34" since "9" is larger than "5".

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(),
         [](int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });

    string ans;
    for (int num : nums) {
        ans += to_string(num);
    }

    return ans[0] == '0' ? "0" : ans;
}
