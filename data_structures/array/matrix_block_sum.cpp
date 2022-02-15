/*
    Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

        i - k <= r <= i + k,
        j - k <= c <= j + k, and
        (r, c) is a valid position in the matrix.
*/

//Uses idea from haar cascade
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> answer(m, std::vector<int>(n, 0));
    vector<vector<int>> prefix(m, std::vector<int>(n, 0));

    //Build prefix sum array
    prefix[0][0] = mat[0][0];
    for (int i = 1; i < m; i++) {
        prefix[i][0] = prefix[i-1][0] + mat[i][0];
    }

    for (int i = 1; i < n; i++) {
        prefix[0][i] = prefix[0][i-1] + mat[0][i];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j ++) {
            prefix[i][j] = mat[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j ++) {
            int br = min(i + k, m - 1);
            int bc = min(j + k, n - 1);
            answer[i][j] = prefix[br][bc];
            answer[i][j] -= ((i - k - 1) >= 0) ?  prefix[i - k - 1][bc] : 0;
            answer[i][j] -= ((j - k - 1) >= 0) ?  prefix[br][j - k - 1] : 0;
            answer[i][j] += ((i - k - 1) >= 0 && (j - k - 1) >= 0) ? 
                            prefix[i - k - 1][j - k - 1] : 0;
        }
    }
    return answer;
}
