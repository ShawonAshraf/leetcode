#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for the Longest Common Prefix problem.
 */
class Solution {
public:
    /**
     * @brief Finds the longest common prefix string amongst an array of strings.
     *
     * This method uses a "vertical scanning" approach. It assumes the first string
     * in the array is the initial common prefix. It then iterates through the
     * characters of this first string (from left to right). For each character,
     * it checks if that same character exists at the same position in all other
     * strings in the array.
     *
     * The process stops as soon as a character mismatch is found or when one of
     * the other strings is shorter than the current prefix length. The common
     * prefix found up to that point is then returned.
     *
     * If the loop completes without finding any mismatches, the entire first
     * string is the common prefix.
     *
     * The time complexity is O(S), where S is the sum of all characters in all strings,
     * as in the worst case, all characters are compared.
     * The space complexity is O(1).
     *
     * @param strs A vector of strings.
     * @return The longest common prefix string. If none exists, returns an empty string.
     */
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // If the input vector is empty, there's no common prefix.
        if (strs.empty()) {
            return "";
        }

        // Iterate through the characters of the first string.
        for (int i = 0; i < strs[0].length(); ++i) {
            char currentChar = strs[0][i];
            
            // Compare this character with the character at the same position
            // in all other strings.
            for (int j = 1; j < strs.size(); ++j) {
                // If we've reached the end of another string, or if the characters
                // don't match, we have found the end of the common prefix.
                if (i == strs[j].length() || strs[j][i] != currentChar) {
                    // Return the substring of the first string up to the current position.
                    return strs[0].substr(0, i);
                }
            }
        }

        // If the loop completes, the entire first string is the common prefix.
        return strs[0];
    }
};
