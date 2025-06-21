#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/**
 * @class Solution
 * @brief Contains the logic for finding the median of two sorted arrays.
 */
class Solution {
public:
    /**
     * @brief Finds the median of two sorted arrays.
     *
     * This method uses a binary search approach on the smaller of the two arrays
     * to find the correct partition point. The goal is to divide the combined
     * elements into two halves: a left part and a right part, where every element
     * in the left part is less than or equal to every element in the right part.
     *
     * Once this partition is found, the median can be determined from the boundary
     * elements (the maximum of the left part and the minimum of the right part).
     *
     * The time complexity is O(log(min(m, n))) because we perform a binary search
     * on the smaller of the two arrays. The space complexity is O(1).
     *
     * @param nums1 The first sorted vector of integers.
     * @param nums2 The second sorted vector of integers.
     * @return The median of the two sorted arrays as a double.
     */
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to simplify the binary search logic.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();
        int low = 0, high = n1;

        while (low <= high) {
            // Partition nums1 at 'cut1'.
            int cut1 = low + (high - low) / 2;
            // The corresponding partition in nums2 is 'cut2'.
            // The '+ 1' handles both even and odd total lengths correctly for the left partition size.
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Determine the four boundary elements for the partitions.
            // left1 is the max element on the left side of the cut in nums1.
            int left1 = (cut1 == 0) ? std::numeric_limits<int>::min() : nums1[cut1 - 1];
            // right1 is the min element on the right side of the cut in nums1.
            int right1 = (cut1 == n1) ? std::numeric_limits<int>::max() : nums1[cut1];
            
            // left2 is the max element on the left side of the cut in nums2.
            int left2 = (cut2 == 0) ? std::numeric_limits<int>::min() : nums2[cut2 - 1];
            // right2 is the min element on the right side of the cut in nums2.
            int right2 = (cut2 == n2) ? std::numeric_limits<int>::max() : nums2[cut2];

            // Check if we have found the correct partition.
            if (left1 <= right2 && left2 <= right1) {
                // If the total number of elements is even.
                if ((n1 + n2) % 2 == 0) {
                    return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
                } else { // If the total number of elements is odd.
                    return std::max(left1, left2);
                }
            } else if (left1 > right2) {
                // The cut in nums1 is too far right. Move left.
                high = cut1 - 1;
            } else { // left2 > right1
                // The cut in nums1 is too far left. Move right.
                low = cut1 + 1;
            }
        }

        // Should not be reached given the problem constraints.
        return 0.0;
    }
};