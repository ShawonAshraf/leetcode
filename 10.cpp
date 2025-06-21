#include <iostream>
#include <string>
#include <vector>

/**
 * @class Solution
 * @brief Contains the logic for the Regular Expression Matching problem.
 */
class Solution {
private:
    // Memoization table to store results of subproblems.
    // -1: not computed, 0: false, 1: true
    std::vector<std::vector<int>> memo;

    /**
     * @brief Recursive helper function with memoization to perform the matching.
     * @param s The input string.
     * @param p The pattern string.
     * @param i Current index in the string s.
     * @param j Current index in the pattern p.
     * @return true if s[i:] matches p[j:], false otherwise.
     */
    bool dp(const std::string& s, const std::string& p, int i, int j) {
        // If the result for this state (i, j) is already computed, return it.
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        // Base case: If the pattern is exhausted, the string must also be exhausted for a match.
        if (j == p.length()) {
            return memo[i][j] = (i == s.length());
        }

        bool ans;
        // Check if the current characters match or if the pattern has a '.'
        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

        // Handle the '*' wildcard
        if (j + 1 < p.length() && p[j + 1] == '*') {
            // Two possibilities for '*':
            // 1. The '*' matches zero of the preceding element.
            //    In this case, we skip the character and the '*' (move j by 2).
            // 2. The '*' matches one or more of the preceding element.
            //    This is only possible if the first characters match.
            //    If they do, we advance the string pointer (i) but keep the pattern pointer (j)
            //    the same, as '*' can match multiple characters.
            ans = dp(s, p, i, j + 2) || (first_match && dp(s, p, i + 1, j));
        } else {
            // No '*' wildcard. We need a match at the current characters,
            // and the rest of the strings must also match.
            ans = first_match && dp(s, p, i + 1, j + 1);
        }

        // Store the result in the memoization table and return it.
        return memo[i][j] = ans;
    }

public:
    /**
     * @brief Implements regular expression matching with support for '.' and '*'.
     *
     * This function serves as an entry point, initializing the memoization table
     * and calling the recursive helper function `dp`.
     *
     * The time complexity is O(s.length * p.length) due to the memoization of subproblems.
     * The space complexity is O(s.length * p.length) for the memoization table.
     *
     * @param s The input string.
     * @param p The pattern string.
     * @return true if the pattern matches the entire string, false otherwise.
     */
    bool isMatch(std::string s, std::string p) {
        // Initialize the memoization table with -1 (not computed).
        memo.assign(s.length() + 1, std::vector<int>(p.length() + 1, -1));
        return dp(s, p, 0, 0);
    }
};
