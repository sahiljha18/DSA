int dp[201][201];

int fun(int i, int j, vector<vector<int>>& grid) {
    int n = grid.size();

    if (j < 0 || j >= n) {
        return 1e9;
    }

    if (i == n - 1) {
        return grid[i][j];
    }

    if (dp[i][j] != -1e9) {
        return dp[i][j];
    }

    int c1 = grid[i][j] + fun(i + 1, j, grid);
    int c2 = grid[i][j] + fun(i + 1, j - 1, grid);
    int c3 = grid[i][j] + fun(i + 1, j + 1, grid);

    return dp[i][j] = min({c1, c2, c3});
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                dp[i][j] = -1e9;
            }
        }

        int ans = 1e9;

        for (int j = 0; j < n; j++) {
            ans = min(ans, fun(0, j,matrix ));
        }

        return ans;
    }
};