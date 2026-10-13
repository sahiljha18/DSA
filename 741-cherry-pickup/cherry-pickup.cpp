
class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int c2 = r1 + c1 - r2;

        // Out of bounds or blocked cells
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
            grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1000000;
        }

        // Destination reached
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        // Already calculated
        if (dp[r1][c1][r2] != -1) {
            return dp[r1][c1][r2];
        }

        int cherries = grid[r1][c1];

        // If both people are in different cells, count both
        if (r1 != r2 || c1 != c2) {
            cherries += grid[r2][c2];
        }

        int best = max({
            solve(r1 + 1, c1, r2 + 1, grid), // Both down
            solve(r1 + 1, c1, r2, grid),     // First down, second right
            solve(r1, c1 + 1, r2 + 1, grid), // First right, second down
            solve(r1, c1 + 1, r2, grid)      // Both right
        });

        cherries += best;

        return dp[r1][c1][r2] = cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();

        dp.assign(n, vector<vector<int>>(
            n, vector<int>(n, -1)
        ));

        int ans = solve(0, 0, 0, grid);

        return max(0, ans);
    }
};
