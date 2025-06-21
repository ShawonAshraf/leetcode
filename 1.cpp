#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @class Solution
 * @brief Contains the logic to solve the Two Sum problem.
 */
class Solution {
public:
    /**
     * @brief Finds two numbers in a vector such that they add up to a specific target.
     * * This method uses a hash map for an efficient O(n) time complexity solution.
     * It iterates through the array once. For each element, it checks if the
     * required "complement" (target - current element) has already been seen.
     * If the complement is found in the map, it means we have found the solution.
     * If not, it adds the current element and its index to the map for future checks.
     * * @param nums A vector of integers.
     * @param target The target integer sum.
     * @return A vector containing the indices of the two numbers.
     */
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create a hash map to store numbers we have seen and their corresponding indices.
        // Key: number from the `nums` vector.
        // Value: index of that number.
        std::unordered_map<int, int> numMap;

        // Iterate through the vector of numbers.
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed to reach the target.
            // complement = target - current_number
            int complement = target - nums[i];

            // Check if the complement exists as a key in our map.
            // .count() is an efficient way to check for key existence.
            if (numMap.count(complement)) {
                // If the complement is in the map, we have found our pair.
                // The value associated with the complement key is its index.
                // We return a vector with the complement's index and the current index.
                return {numMap[complement], i};
            }

            // If the complement was not found, add the current number and its index
            // to the map. This makes it available for future lookups.
            // We do this after the check to ensure we don't use the same element twice.
            numMap[nums[i]] = i;
        }

        // The problem statement guarantees that exactly one solution exists,
        // so the function will always return from within the loop.
        // This return is included to satisfy the compiler's requirement for a return path,
        // in case the function could theoretically finish without returning.
        return {};
    }
};