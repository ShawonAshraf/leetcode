#include <iostream>
#include <string>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for finding the longest palindromic substring.
 */
class Solution {
public:
    /**
     * @brief Finds the longest palindromic substring in a given string.
     *
     * This method uses the "Expand Around Center" approach. It iterates through
     * each character of the string and treats it as a potential center of a
     * palindrome. For each character, it checks for two types of palindromes:
     * 1. An odd-length palindrome with the character as its single center (e.g., "aba").
     * 2. An even-length palindrome with the character and the next one as its center (e.g., "abba").
     *
     * A helper function, expandAroundCenter, is used to find the length of the
     * palindrome for a given center. The function keeps track of the start
     * and end indices of the longest palindrome found so far.
     *
     * The overall time complexity is O(n^2) because expanding from each center can take up to O(n) time.
     * The space complexity is O(1).
     *
     * @param s The input string.
     * @return The longest palindromic substring.
     */
    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) {
            return "";
        }

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); ++i) {
            // Check for odd-length palindromes (center is at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = std::max(len1, len2);

            if (len > maxLength) {
                maxLength = len;
                // Calculate the new start position of the longest palindrome
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }

private:
    /**
     * @brief Helper function to expand around a center and find palindrome length.
     *
     * @param s The input string.
     * @param left The left pointer of the center.
     * @param right The right pointer of the center.
     * @return The length of the palindrome found.
     */
    int expandAroundCenter(const std::string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // The length of the palindrome is right - left - 1
        return right - left - 1;
    }
};
