#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

/**
 * @class Solution
 * @brief Contains the logic for the 3Sum problem.
 */
class Solution {
public:
    /**
     * @brief Finds all unique triplets in the array which give the sum of zero.
     *
     * This method solves the 3Sum problem efficiently. The main steps are:
     * 1. Sort the input array `nums`. This allows us to use the two-pointer
     * technique and easily skip duplicate elements.
     * 2. Iterate through the array with a primary pointer `i`.
     * 3. For each element `nums[i]`, use two other pointers, `left` (starting at `i+1`)
     * and `right` (starting at the end of the array), to find a pair
     * that sums up to `-nums[i]`.
     * 4. If `nums[i] + nums[left] + nums[right]` is 0, we've found a triplet.
     * We add it to our result set. To avoid duplicates, we then advance
     * the `left` and `right` pointers past any subsequent identical elements.
     * 5. If the sum is less than 0, we increment `left` to get a larger sum.
     * 6. If the sum is greater than 0, we decrement `right` to get a smaller sum.
     * 7. To avoid processing the same starting number multiple times, we skip
     * over any duplicates for the primary pointer `i`.
     *
     * The time complexity is O(n^2) due to the nested loop structure (the outer
     * for-loop and the inner while-loop of the two pointers). The sort takes O(n log n).
     * The space complexity depends on the implementation, but is O(1) or O(n) if
     * we include the space for the output.
     *
     * @param nums A vector of integers.
     * @return A vector of vectors, where each inner vector is a unique triplet summing to zero.
     */
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 3) {
            return result;
        }

        // 1. Sort the array
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            // 7. Skip duplicate elements for the first number of the triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // 4. Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicate elements for the second and third numbers
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move pointers to find new unique triplets
                    left++;
                    right--;
                } else if (sum < 0) {
                    // 5. Sum is too small, move left pointer to the right
                    left++;
                } else {
                    // 6. Sum is too large, move right pointer to the left
                    right--;
                }
            }
        }
        return result;
    }
};
