class Solution {
public:

    int fun(int i, int j, string &t1, string &t2, vector<vector<int>> &dp) {

        // Base case
        if (i >= t1.size() || j >= t2.size())
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters same
        if (t1[i] == t2[j]) {
            return dp[i][j] = 1 + fun(i + 1, j + 1, t1, t2, dp);
        }

        // Characters different
        int a = fun(i + 1, j, t1, t2, dp);
        int b = fun(i, j + 1, t1, t2, dp);

        return dp[i][j] = max(a, b);
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return fun(0, 0, text1, text2, dp);
    }
};