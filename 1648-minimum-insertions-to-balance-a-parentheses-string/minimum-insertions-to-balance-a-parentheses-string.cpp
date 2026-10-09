
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                // If next character is also ')',
                // use both as one closing pair.
                if (i + 1 < s.length() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // Match the closing pair with an opening '('.
                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert '(' because no opening exists.
                    ans++;
                }
            }
        }

        // Each remaining '(' requires two ')'.
        ans += open * 2;

        return ans;
    }
};