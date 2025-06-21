#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

/**
 * @class Solution
 * @brief Contains the logic for the myAtoi (string to integer) problem.
 */
class Solution {
public:
    /**
     * @brief Converts a string to a 32-bit signed integer.
     *
     * This function implements the standard `atoi` behavior. It follows these steps:
     * 1. Ignores any leading whitespace.
     * 2. Checks for an optional '+' or '-' sign.
     * 3. Reads in consecutive digits, building the integer.
     * 4. Stops reading when a non-digit character is encountered.
     * 5. Handles overflow by clamping the result to the 32-bit integer range
     * [INT_MIN, INT_MAX]. If the number is too large, INT_MAX is returned.
     * If it's too small, INT_MIN is returned.
     *
     * The time complexity is O(n) where n is the length of the string, as we
     * iterate through the string once. The space complexity is O(1).
     *
     * @param s The input string to convert.
     * @return The converted integer.
     */
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        int result = 0;

        // 1. Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Determine the sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        const int INT_MAX_DIV_10 = std::numeric_limits<int>::max() / 10;
        const int INT_MAX_MOD_10 = std::numeric_limits<int>::max() % 10;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow before modifying the result.
            // If result > INT_MAX / 10, then result * 10 will overflow.
            // If result == INT_MAX / 10, then it overflows if the next digit > 7 (for INT_MAX).
            if (result > INT_MAX_DIV_10 || (result == INT_MAX_DIV_10 && digit > INT_MAX_MOD_10)) {
                return (sign == 1) ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }

            result = result * 10 + digit;
            i++;
        }

        // 4. Return the final result with the correct sign.
        return result * sign;
    }
};
