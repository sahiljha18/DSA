
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();
        int ans = INT_MAX;

        // Try every starting index
        for (int i = 0; i < n; i++) {

            int sum = 0;

            // Try different subarray lengths
            for (int j = i; j < n; j++) {

                sum += nums[j];

                int len = j - i + 1;

                // Check length and positive sum
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }

                // No need to check longer subarrays
                if (len >= r) {
                    break;
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
