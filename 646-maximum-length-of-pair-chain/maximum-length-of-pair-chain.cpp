class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      
           sort(pairs.begin(), pairs.end(),
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
            });
        int count = 0;
        int end = -10000;

        for(auto p : pairs) {

            if(end < p[0]) {
                count++;
                end = p[1];
            }
        }

        return count;
    }
};