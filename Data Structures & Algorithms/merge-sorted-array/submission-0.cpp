class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums1Copy(nums1.begin(), nums1.begin() + m);
        int index = 0, i = 0, j = 0;
        // Index iterates nums1.
        // i iterates nums1Copy.
        // j iterates nums2.

        while (index < m + n)
        {
            if (j >= n || (i < m && nums1Copy[i] <= nums2[j]))
            {
                nums1[index++] = nums1Copy[i++];
            }
            else
            {
                nums1[index++] = nums2[j++];
            }
        }
    }
};