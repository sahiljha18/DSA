
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, (int)diff[i]);
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        // Find the minimum maximum difference possible
        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int i = 0; i < n; i++) {
                if (diff[i] > mid) {
                    need += diff[i] - mid;
                }
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long remaining = k;

        for (int i = 0; i < n; i++) {
            if (diff[i] > low) {
                remaining -= diff[i] - low;
                diff[i] = low;
            }
        }

        // Spend leftover operations reducing differences at the boundary
        for (int i = 0; i < n && remaining > 0; i++) {
            if (diff[i] == low && diff[i] > 0) {
                diff[i]--;
                remaining--;
            }
        }

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};
