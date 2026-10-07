 int fun(string s, int k) {
        if (s.length() < k)
            return 0;

        // frequency of characters
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Find a character whose frequency is less than k
        for (int i = 0; i < s.length(); i++) {

            if (freq[s[i] - 'a'] < k) {

                // split at this character
                string left = s.substr(0, i);
                string right = s.substr(i + 1);

                return max(fun(left, k), fun(right, k));
            }
        }

        // Every character appears >= k times
        return s.length();
    }
class Solution {
public:
    int longestSubstring(string s, int k) {
        return fun(s, k);
    }
};