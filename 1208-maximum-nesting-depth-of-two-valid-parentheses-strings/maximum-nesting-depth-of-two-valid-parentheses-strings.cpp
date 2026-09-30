class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int k = 0;
        vector<int> ans;

        for (char ch : seq) {
            if (ch == '(') {
                k++;
                ans.push_back(k % 2);
            } else {
                ans.push_back(k % 2);
                k--;
            }
        }

        return ans;
    }
};