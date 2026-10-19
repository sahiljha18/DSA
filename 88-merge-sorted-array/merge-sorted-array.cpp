class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;       // Start of nums1
        int j = 0;       // Start of nums2
        int k = 0;       // Position to insert

        vector<int> temp;

        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }

        for (int x = 0; x < m + n; x++) {
            nums1[x] = temp[x];
        }
    }
};