#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * @class Solution
 * @brief Contains the logic for the Letter Combinations of a Phone Number problem.
 */
class Solution {
private:
    std::vector<std::string> result;
    std::unordered_map<char, std::string> phoneMap;

    /**
     * @brief A recursive backtracking function to generate letter combinations.
     *
     * This function explores all possible letter combinations for a given sequence of digits.
     * It builds a combination string character by character.
     *
     * @param index The current index in the `digits` string we are processing.
     * @param digits The input string of digits.
     * @param currentCombination The combination string built so far.
     */
    void backtrack(int index, const std::string& digits, std::string& currentCombination) {
        // Base case: If the current combination is the same length as the digits string,
        // we have found a complete combination. Add it to the result and return.
        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        // Get the letters corresponding to the current digit.
        char digit = digits[index];
        const std::string& letters = phoneMap.at(digit);

        // Iterate through each letter for the current digit.
        for (char letter : letters) {
            // Add the letter to the current combination.
            currentCombination.push_back(letter);
            // Recursively call for the next digit.
            backtrack(index + 1, digits, currentCombination);
            // Backtrack: remove the letter we just added to explore other possibilities.
            currentCombination.pop_back();
        }
    }

public:
    /**
     * @brief Given a string containing digits from 2-9, return all possible
     * letter combinations that the number could represent.
     *
     * This method initializes the digit-to-letter mapping and kicks off the
     * backtracking process to generate all combinations.
     *
     * The time complexity is O(4^N * N), where N is the length of the digits string.
     * 4^N is for the number of combinations, and N is for creating a copy of the string for each.
     * The space complexity is O(N) for the recursion stack depth.
     *
     * @param digits The input string of digits.
     * @return A vector of strings containing all possible letter combinations.
     */
    std::vector<std::string> letterCombinations(std::string digits) {
        // Handle the edge case of an empty input string.
        if (digits.empty()) {
            return {};
        }

        // Initialize the phone number mapping.
        phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        result.clear();
        std::string currentCombination = "";
        backtrack(0, digits, currentCombination);

        return result;
    }
};
