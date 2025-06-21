#include <iostream>
#include <string>
#include <unordered_map>

/**
 * @class Solution
 * @brief Contains the logic for the Roman to Integer conversion problem.
 */
class Solution {
public:
    /**
     * @brief Converts a Roman numeral string to its integer representation.
     *
     * This method iterates through the Roman numeral string from left to right.
     * It uses a hash map to get the integer value of each Roman symbol.
     *
     * The core logic handles the subtractive cases (e.g., IV, IX, XL).
     * If the value of the current symbol is less than the value of the next
     * symbol, it means the current symbol should be subtracted from the total.
     * Otherwise, the current symbol's value is added to the total.
     *
     * For example, in "MCMXCIV":
     * - M (1000): Add 1000. Total = 1000.
     * - C (100) < M (1000): Subtract 100. Total = 900.
     * - M (1000): Add 1000. Total = 1900.
     * - X (10) < C (100): Subtract 10. Total = 1890.
     * - C (100): Add 100. Total = 1990.
     * - I (1) < V (5): Subtract 1. Total = 1989.
     * - V (5): Add 5. Total = 1994.
     *
     * The logic is adjusted slightly by iterating up to the second to last character
     * and always adding the value of the very last character.
     *
     * The time complexity is O(n) where n is the length of the string, as we
     * iterate through the string once. The space complexity is O(1) as the map size is constant.
     *
     * @param s The Roman numeral string, guaranteed to be valid and in the range [1, 3999].
     * @return The integer representation of the Roman numeral.
     */
    int romanToInt(std::string s) {
        // Map to store the values of Roman symbols.
        std::unordered_map<char, int> roman_map = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // Check if the current symbol is part of a subtractive pair.
            // This happens if it's not the last symbol and its value is
            // less than the next symbol's value.
            if (i < n - 1 && roman_map[s[i]] < roman_map[s[i + 1]]) {
                total -= roman_map[s[i]];
            } else {
                total += roman_map[s[i]];
            }
        }
        return total;
    }
};
