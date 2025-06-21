#include <iostream>
#include <string>
#include <vector>

/**
 * @class Solution
 * @brief Contains the logic for the Integer to Roman conversion problem.
 */
class Solution {
public:
    /**
     * @brief Converts an integer to its Roman numeral representation.
     *
     * This method uses a greedy approach. It iterates through a pre-defined list
     * of Roman numeral values from largest to smallest (e.g., 1000, 900, 500...).
     * For each value, it repeatedly subtracts it from the input number and appends
     * the corresponding Roman symbol to the result string until the number is
     * smaller than the current value.
     *
     * This works because the Roman numeral system is essentially a base system
     * with special cases for 4s and 9s, which are handled by including them
     * in the value list (e.g., 900 for "CM", 400 for "CD").
     *
     * The time complexity is constant since the loop runs a fixed number of times,
     * and the inner while loop runs at most 3 times for each value.
     * The space complexity is O(1).
     *
     * @param num The integer to convert, guaranteed to be between 1 and 3999.
     * @return The Roman numeral representation as a string.
     */
    std::string intToRoman(int num) {
        // Define the values and their corresponding Roman symbols, from largest to smallest.
        // Including the subtractive cases (900, 400, 90, 40, 9, 4) makes the greedy approach work.
        const std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        std::string result = "";
        
        // Greedily subtract the largest possible values from num.
        for (int i = 0; i < values.size(); ++i) {
            // While the number is large enough to subtract the current value
            while (num >= values[i]) {
                // Append the corresponding symbol
                result += symbols[i];
                // Subtract the value from the number
                num -= values[i];
            }
        }
        return result;
    }
};
