#include <iostream>
#include <string>
#include <vector>

/**
 * @class Solution
 * @brief Contains the logic for the Zigzag Conversion problem.
 */
class Solution {
public:
    /**
     * @brief Converts a string into a zigzag pattern and then reads it line by line.
     *
     * This method simulates the writing of the string's characters in a zigzag
     * pattern across a specified number of rows. It maintains a vector of strings,
     * where each string represents a row.
     *
     * It iterates through the input string character by character, appending each
     * to the correct row. The direction of movement (down or up the rows) is
     * tracked and reversed when the top or bottom row is reached.
     *
     * Finally, all the row strings are concatenated to produce the final output string.
     *
     * The time complexity is O(n) where n is the length of the string, as we
     * iterate through the string once. The space complexity is O(n) to store
     * the rows.
     *
     * @param s The input string.
     * @param numRows The number of rows for the zigzag pattern.
     * @return The converted string.
     */
    std::string convert(std::string s, int numRows) {
        // If numRows is 1, the zigzag pattern is just the string itself.
        if (numRows == 1) {
            return s;
        }

        std::vector<std::string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Iterate through each character of the input string.
        for (char c : s) {
            rows[currentRow] += c;

            // Reverse direction if we are at the top or bottom row.
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move to the next row based on the current direction.
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all the rows to form the final result.
        std::string result = "";
        for (const std::string& row : rows) {
            result += row;
        }

        return result;
    }
};
