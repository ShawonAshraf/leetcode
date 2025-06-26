#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for finding the kth smallest product of two sorted arrays.
 */
class Solution {
private:
    /**
     * @brief Counts the number of products nums1[i] * nums2[j] that are <= val.
     * This is the core helper for the binary search on the answer. It iterates
     * through nums1 and for each element, efficiently finds the number of
     * corresponding elements in nums2 that satisfy the product condition.
     * @param nums1 The first sorted array.
     * @param nums2 The second sorted array.
     * @param val The value to compare products against.
     * @return The count of products <= val.
     */
    long long countLessEqual(const std::vector<int>& nums1, const std::vector<int>& nums2, long long val) {
        long long count = 0;
        for (long long n1 : nums1) {
            if (n1 > 0) {
                // Find count of n2 such that n2 <= val / n1
                // We use upper_bound to find the first element > val/n1,
                // the distance from the beginning is the count of elements <= val/n1.
                long long target = floor((double)val / n1);
                auto it = std::upper_bound(nums2.begin(), nums2.end(), target);
                count += (it - nums2.begin());
            } else if (n1 < 0) {
                // Find count of n2 such that n1*n2 <= val => n2 >= val / n1 (inequality flips)
                // We use lower_bound to find the first element >= val/n1.
                // The count is all elements from this point to the end.
                long long target = ceil((double)val / n1);
                auto it = std::lower_bound(nums2.begin(), nums2.end(), target);
                count += (nums2.end() - it);
            } else { // n1 == 0
                // If val >= 0, then 0 * n2 (which is 0) is always <= val.
                // So, all elements of nums2 form a valid pair.
                if (val >= 0) {
                    count += nums2.size();
                }
            }
        }
        return count;
    }

public:
    /**
     * @brief Finds the kth smallest product of pairs from two sorted arrays.
     *
     * This method uses binary search on the answer space. The range of possible
     * products is from -10^10 to 10^10.
     * For a given `mid` value in this range, we can efficiently count how many
     * products are less than or equal to `mid` using the `countLessEqual` helper function.
     *
     * - If `countLessEqual(mid)` is >= k, it means `mid` could be our answer, or the
     * true answer is smaller. So we try a smaller range by setting `high = mid - 1`.
     * - If `countLessEqual(mid)` is < k, it means `mid` is too small, and the answer
     * must be larger. So we set `low = mid + 1`.
     *
     * The loop continues until `low` and `high` converge, giving the kth smallest product.
     * The time complexity is O(m * log(n) * log(R)), where m and n are array lengths
     * and R is the range of possible product values.
     *
     * @param nums1 The first sorted integer array.
     * @param nums2 The second sorted integer array.
     * @param k The 1-based index of the smallest product to find.
     * @return The kth smallest product.
     */
    long long kthSmallestProduct(std::vector<int>& nums1, std::vector<int>& nums2, long long k) {
        long long low = -1e10 - 7;
        long long high = 1e10 + 7;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (countLessEqual(nums1, nums2, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};