// ***
//
// Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element
// in the matrix.
//
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
// Example:
//
// matrix = [
//    [ 1,  5,  9],
//    [10, 11, 13],
//    [12, 13, 15]
// ],
// k = 8,
//
// return 13.
//
// ***

// Prioirty queue, O(nlogn) time, O(n) space.
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> pq;

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            pq.push(matrix[i][j]);

            // Always keep the k smallest elements in the priority_queue.
            // So the top() of the priority_queue is always the kth smallest element.
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    return pq.top();
}

// Binary search using std::lower_bound(), O(nlogn) time, O(1) space.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Note here that left and right are numbers, not index.
        // Given that rows and columns are sorted in ascending order,
        // therefore the smallest element is matrix[0][0] and largest element is matrix.back().back().
        int left = matrix[0][0], right = matrix.back().back() + 1;

        // Eventually, left and right will converge to the Kth smallest element.
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Count the total number of elements in the matrix that are smaller than mid
            int count = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count == k) {
                right = mid;
            } else if (count < k) {
                left = mid + 1;
            } else if (count > k) {
                right = mid;
            }
        }

        return right;
    }
};

