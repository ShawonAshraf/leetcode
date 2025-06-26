#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for the Candy distribution problem.
 */
class Solution {
public:
    /**
     * @brief Calculates the minimum number of candies to distribute to children based on their ratings.
     *
     * This method uses a greedy two-pass approach to solve the problem:
     * 1. Initialize a `candies` vector where every child gets one candy. This
     * satisfies the first requirement that each child must have at least one.
     *
     * 2. First Pass (Left to Right): Iterate from the second child to the end.
     * If a child has a higher rating than their left neighbor, give them one
     * more candy than their left neighbor. This ensures the "higher rating gets
     * more candies" rule is satisfied with respect to the left neighbor.
     *
     * 3. Second Pass (Right to Left): Iterate from the second-to-last child
     * back to the beginning. If a child has a higher rating than their right
     * neighbor, they must have more candies. We take the maximum of their current
     * candy count and their right neighbor's count plus one. This ensures the
     * rule is satisfied with respect to the right neighbor, without violating
     * the condition established in the first pass.
     *
     * 4. Finally, the sum of all elements in the `candies` vector is the
     * minimum total number of candies required.
     *
     * The time complexity is O(n) due to the two linear passes through the array.
     * The space complexity is O(n) for the `candies` vector.
     *
     * @param ratings A vector of integers representing the ratings of the children.
     * @return The minimum total number of candies needed.
     */
    int candy(std::vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) {
            return 0;
        }

        // 1. Give each child one candy initially.
        std::vector<int> candies(n, 1);

        // 2. First pass: left to right.
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 3. Second pass: right to left.
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        // 4. Calculate the total number of candies.
        int total_candies = 0;
        for (int count : candies) {
            total_candies += count;
        }
        
        return total_candies;
    }
};