    bool check(string &small, string &big) {

        if(big.size() != small.size() + 1)
            return false;

        int i = 0;
        int j = 0;

        while(i < small.size() && j < big.size()) {

            if(small[i] == big[j]) {
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return i == small.size();
    }

class Solution {
public:
    int longestStrChain(vector<string>& words) {
             sort(words.begin(), words.end(),
            [](string &a, string &b) {
                return a.size() < b.size();
            });

        int n = words.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(check(words[j], words[i])) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};