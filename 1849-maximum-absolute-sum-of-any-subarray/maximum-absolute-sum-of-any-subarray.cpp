class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;

        int currMax = 0;
        int currMin = 0;

        for (int x : nums) {
            currMax = max(x, currMax + x);
            currMin = min(x, currMin + x);

            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }

        return max(maxSum, abs(minSum));
    }
};