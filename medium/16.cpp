#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // For std::abs
#include <limits> // For std::numeric_limits

/**
 * @class Solution
 * @brief Contains the logic for the 3Sum Closest problem.
 */
class Solution {
public:
    /**
     * @brief Finds three integers in nums such that the sum is closest to target.
     *
     * This method adapts the two-pointer approach to find the sum of a triplet
     * that is closest to a given target value. The main steps are:
     * 1. Sort the input array `nums`. This allows for efficient traversal with pointers.
     * 2. Initialize a `closestSum` variable to track the sum that is currently closest
     * to the target. It's initialized with the sum of the first three elements.
     * 3. Iterate through the array with a primary pointer `i`.
     * 4. For each element `nums[i]`, use two other pointers, `left` (starting at `i+1`)
     * and `right` (starting at the end of the array).
     * 5. Calculate the `currentSum` of the triplet `(nums[i], nums[left], nums[right])`.
     * 6. If the absolute difference between `currentSum` and `target` is smaller
     * than the difference for `closestSum`, update `closestSum` to `currentSum`.
     * 7. If `currentSum` is less than `target`, increment `left` to increase the sum.
     * 8. If `currentSum` is greater than `target`, decrement `right` to decrease the sum.
     * 9. If `currentSum` equals `target`, we've found the exact match and can return it immediately.
     *
     * The time complexity is O(n^2) due to the nested loop structure (the outer
     * for-loop and the inner while-loop of the two pointers). The sort takes O(n log n).
     * The space complexity is O(1) (excluding the input storage).
     *
     * @param nums A vector of integers.
     * @param target The target integer.
     * @return The sum of the three integers closest to the target.
     */
    int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) {
            // As per constraints, this case won't be reached.
            // But it's good practice for robustness.
            return 0; 
        }

        // 1. Sort the array
        std::sort(nums.begin(), nums.end());

        // 2. Initialize closestSum with the sum of the first three elements.
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // 9. If the sum is exactly the target, it's the closest possible.
                if (currentSum == target) {
                    return target;
                }

                // 6. Check if the current sum is closer to the target than the previous closest sum.
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // 7. & 8. Move pointers based on comparison with the target.
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closestSum;
    }
};
