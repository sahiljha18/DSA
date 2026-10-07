class Solution {
public:
    set<string> st;

    void solve(string &s, int i, int left, int right,
               int balance, string curr) {

        // End of string
        if(i == s.size()) {
            if(left == 0 && right == 0 && balance == 0) {
                st.insert(curr);
            }
            return;
        }

        // Current character is '('
        if(s[i] == '(') {

            // Remove '('
            if(left > 0) {
                solve(s, i + 1, left - 1, right, balance, curr);
            }

            // Keep '('
            solve(s, i + 1, left, right, balance + 1, curr + '(');
        }

        // Current character is ')'
        else if(s[i] == ')') {

            // Remove ')'
            if(right > 0) {
                solve(s, i + 1, left, right - 1, balance, curr);
            }

            // Keep ')' only if it has a matching '('
            if(balance > 0) {
                solve(s, i + 1, left, right, balance - 1, curr + ')');
            }
        }

        // Letter
        else {
            solve(s, i + 1, left, right, balance, curr + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int left = 0;
        int right = 0;

        // Find how many '(' and ')' need to be removed
        for(char c : s) {

            if(c == '(') {
                left++;
            }
            else if(c == ')') {

                if(left > 0)
                    left--;
                else
                    right++;
            }
        }

        string curr = "";

        solve(s, 0, left, right, 0, curr);

        return vector<string>(st.begin(), st.end());
    }
};