#include <limits.h>

class Solution
{
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        int sum = A.size() + B.size();
        
        if (sum & 1)
        {
            return findTheKthNum(A, B, 0, 0, sum / 2 + 1);
        }
        else
        {
            return (findTheKthNum(A, B, 0, 0, sum / 2) + findTheKthNum(A, B, 0, 0, sum / 2 + 1)) / 2.0;
        }
    }
    double findTheKthNum(vector<int> &nums1, vector<int> &nums2, int idx1, int idx2, int kth)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if (idx1 >= len1)
        {
            return nums2[idx2 + kth - 1];
        }
        if (idx2 >= len2)
        {
            return nums1[idx1 + kth - 1];
        }
        if (kth == 1)
        {
            return min(nums1[idx1], nums2[idx2]);
        }
        
        int mid_idx_1 = idx1 + kth / 2 - 1;
        int mid_idx_2 = idx2 + kth / 2 - 1;
        
        int mid_value_1 = mid_idx_1 >= len1 ? INT_MAX: nums1[mid_idx_1];
        int mid_value_2 = mid_idx_2 >= len2 ? INT_MAX: nums2[mid_idx_2];
        
        if (mid_value_1 < mid_value_2)
        {
            return findTheKthNum(nums1, nums2, idx1 + kth / 2, idx2, kth - kth / 2);
        }
        else
        {
            return findTheKthNum(nums1, nums2, idx1, idx2 + kth / 2, kth - kth / 2);
        }
        
    }
};
