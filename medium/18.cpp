#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

/**
 * @class Solution
 * @brief Contains the logic for the 4Sum problem.
 */
class Solution {
public:
    /**
     * @brief Finds all unique quadruplets in the array which give the sum of target.
     *
     * This method solves the 4Sum problem by extending the 3Sum approach.
     * 1. The input array `nums` is sorted. This is essential for the two-pointer
     * technique and for skipping duplicates efficiently.
     * 2. Two nested loops are used to fix the first two numbers of the potential
     * quadruplet (at indices `i` and `j`).
     * 3. For each pair `(nums[i], nums[j])`, a two-pointer approach is used on the
     * rest of the array. A `left` pointer starts at `j+1` and a `right` pointer
     * starts at the end of the array.
     * 4. These two pointers search for a pair `(nums[left], nums[right])` such that
     * `nums[i] + nums[j] + nums[left] + nums[right] == target`.
     * 5. To avoid duplicate quadruplets in the result, we skip over any duplicate
     * values for all four pointers (`i`, `j`, `left`, `right`) after finding a valid combination.
     * 6. A 64-bit integer (`long long`) is used for the sum calculation to prevent potential overflow.
     *
     * The time complexity is O(n^3) due to the two nested loops and the inner two-pointer scan.
     * The sort takes O(n log n). The space complexity is O(1) or O(n) if the output storage is included.
     *
     * @param nums A vector of integers.
     * @param target The target integer sum.
     * @return A vector of vectors, where each inner vector is a unique quadruplet summing to target.
     */
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long currentSum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (currentSum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (currentSum < target) {
                        left++;
                    } else { // currentSum > target
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
