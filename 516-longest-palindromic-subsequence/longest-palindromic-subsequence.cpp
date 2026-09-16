 int fun(int i, int j,  string &s, vector<vector<int>> &dp){
     if (i == j)
            return 1;

        if (i > j)
            return 0;

            if (dp[i][j] != -1)
            return dp[i][j];

              if (s[i] == s[j]) {
            return dp[i][j] = 2 + fun(i + 1, j - 1, s, dp);
        }

      
    
      // If characters are different
        int a = fun(i + 1, j, s, dp);
        int b = fun(i, j - 1, s, dp);

        return dp[i][j] = max(a, b);
 }
class Solution {
public:
    int longestPalindromeSubseq(string s) {
           int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return fun(0, n - 1, s, dp);
        
    }
};