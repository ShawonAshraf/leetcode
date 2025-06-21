#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for finding the length of the longest substring
 * without repeating characters.
 */
class Solution {
public:
    /**
     * @brief Calculates the length of the longest substring without repeating characters.
     *
     * This method employs a sliding window approach. A window is a substring
     * defined by a start and end pointer. We expand the window by moving the
     * end pointer. If we encounter a character that is already inside our current
     * window, we shrink the window from the left by moving the start pointer to
     * the position right after the previous occurrence of that character.
     *
     * An unordered_map is used to store the last seen index of each character,
     * allowing for O(1) average time complexity for lookups.
     *
     * The overall time complexity is O(n) because each character is visited at
     * most twice (by the start and end pointers). The space complexity is O(min(m, n))
     * where n is the length of the string and m is the size of the character set.
     *
     * @param s The input string.
     * @return The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(std::string s) {
        // Map to store the last seen index of each character.
        // Key: character, Value: index in the string.
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        
        // 'start' is the starting index of the current non-repeating substring (our window).
        for (int end = 0, start = 0; end < s.length(); ++end) {
            char currentChar = s[end];

            // Check if the current character has been seen before.
            if (charIndexMap.count(currentChar)) {
                // If the character is found, it might be a duplicate within our window.
                // We must move the start of our window to the right of the last
                // occurrence of this character.
                // We take the max with the current 'start' to ensure we don't move
                // the window backward (in cases like "abba").
                start = std::max(start, charIndexMap[currentChar] + 1);
            }

            // Update the last seen index of the current character.
            charIndexMap[currentChar] = end;

            // Calculate the length of the current window and update maxLength if it's larger.
            maxLength = std::max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};