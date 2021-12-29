// ***
//
// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
// ***

// Note that for matrix multiplication to make sense, A[0].size() must be the same as B.size().
//
// A of size (m, k) * B of size (k, n) -> C of size (m, n),
// C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j] + ... + A[i][k] * B[k][j]
// Therefore we need to make sure that A[i][k] != 0 and B[k][j] != 0 when calculating for C[i][j]
// to make sure we don't spend time multiplying 0 by 0.
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));

    for (int i = 0; i < A.size(); ++i) {
        for (int k = 0; k < A[0].size(); ++k) {
            if (A[i][k] != 0) {
                for (int j = 0; j < B[0].size(); ++j) {
                    if (B[k][j] != 0) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
    }

    return C;
}

// Vanilla matrix multiplication
vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> C(A.size(), vector<int>(B[0].size()));

    for (int i = 0; i < A.size(); ++i) {
        for (int k = 0; k < A[0].size(); ++k) {
            for (int j = 0; j < B[0].size(); ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}
