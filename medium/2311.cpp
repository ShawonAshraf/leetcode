#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @class Solution
 * @brief Contains the logic for finding the longest subsequence that forms a binary number <= k.
 */
class Solution {
public:
    /**
     * @brief Finds the length of the longest subsequence of a binary string `s` that forms a number <= k.
     *
     * This method uses a greedy approach, processing the string from right to left.
     * The strategy is based on two key insights:
     * 1. To maximize the length of the subsequence, we should include all '0's, as they
     * increase length without increasing the binary value.
     * 2. To keep the value low while adding '1's, we should prioritize the '1's that
     * correspond to the smallest place values. These are the '1's on the right
     * side of the string.
     *
     * The algorithm iterates from the end of the string to the beginning:
     * - If it encounters a '0', it's always included, so the length count is incremented.
     * - If it encounters a '1', it checks if adding its place value (`power`) to the
     * current `value` would exceed `k`.
     * - If it doesn't exceed `k`, the '1' is included: `value` is updated and length is incremented.
     * - If it does, the '1' is skipped.
     * - The `power` variable keeps track of the current place value (1, 2, 4, 8, ...),
     * and is updated in each step.
     * - An optimization is included: if `power` itself exceeds `k`, no more '1's can be added.
     *
     * @param s The input binary string.
     * @param k The maximum allowed value for the subsequence's binary representation.
     * @return The length of the longest valid subsequence.
     */
    int longestSubsequence(std::string s, int k) {
        int length = 0;
        long long currentValue = 0;
        long long power = 1;
        
        // Iterate from the rightmost character (least significant bit) to the left.
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                // '0's can always be included as they don't add to the value.
                length++;
            } else { // s[i] == '1'
                // Check if adding this '1' would exceed the limit k.
                // Also check if the power itself has become too large.
                if (power <= k && currentValue + power <= k) {
                    currentValue += power;
                    length++;
                }
            }

            // Update the power for the next bit to the left, unless it's already too large to be added.
            if (power <= k) {
                 power *= 2;
            }
        }
        
        return length;
    }
};