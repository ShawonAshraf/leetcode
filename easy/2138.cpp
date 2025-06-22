#include <iostream>
#include <vector>
#include <string>

/**
 * @class Solution
 * @brief Contains the logic for partitioning a string into groups of size k.
 */
class Solution {
public:
    /**
     * @brief Divides a string into an array of strings of size k, with padding.
     *
     * This method iterates through the input string `s` in steps of size `k`.
     * For each step, it extracts a substring of length `k`.
     * If the extracted substring (which happens with the last group) is shorter
     * than `k`, it is padded with the `fill` character until its length is `k`.
     * Each resulting group is added to a string array which is then returned.
     *
     * The time complexity is O(N), where N is the length of the string `s`, as we
     * iterate through the string and perform operations that are proportional to N in total.
     * The space complexity is O(N) to store the resulting array of strings.
     *
     * @param s The input string.
     * @param k The size of each group.
     * @param fill The character to use for padding the last group.
     * @return A string array denoting the composition of every group.
     */
    std::vector<std::string> divideString(std::string s, int k, char fill) {
        std::vector<std::string> result;
        
        // Iterate through the string with a step of k.
        for (int i = 0; i < s.length(); i += k) {
            // Extract a substring of size k. If there are fewer than k characters
            // remaining, substr will just take what's left.
            std::string group = s.substr(i, k);
            
            // Pad the group if its length is less than k.
            while (group.length() < k) {
                group += fill;
            }
            
            result.push_back(group);
        }
        
        return result;
    }
};
