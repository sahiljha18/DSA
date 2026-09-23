class Solution {
public:

    bool fun(int i, int j, string &s1, string &s2,
             string &s3, vector<vector<int>> &dp) {

        int k = i + j;

        if (k == s3.size()) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool takeS1 = false;
        bool takeS2 = false;

        if (i < s1.size() && s1[i] == s3[k]) {
            takeS1 = fun(i + 1, j, s1, s2, s3, dp);
        }

        if (j < s2.size() && s2[j] == s3[k]) {
            takeS2 = fun(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = takeS1 || takeS2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return fun(0, 0, s1, s2, s3, dp);
    }
};