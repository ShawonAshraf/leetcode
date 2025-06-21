#include <iostream>
#include <limits> // Required for std::numeric_limits

/**
 * @class Solution
 * @brief Contains the logic for the Palindrome Number problem.
 */
class Solution {
public:
    /**
     * @brief Checks if an integer is a palindrome without converting it to a string.
     *
     * This method determines if an integer is a palindrome by reversing the
     * second half of the number and comparing it to the first half.
     *
     * Edge cases handled:
     * - Negative numbers are not palindromes.
     * - Any number that ends in 0 (and is not 0 itself) cannot be a palindrome.
     *
     * The algorithm builds a 'revertedNumber' until it's greater than or equal
     * to the remaining original number 'x'. This point marks the middle of the number.
     * Finally, it compares 'x' and 'revertedNumber' to check for the palindrome property.
     * For odd-length numbers, the middle digit is in 'revertedNumber', so we can
     * ignore it by dividing 'revertedNumber' by 10.
     *
     * The time complexity is O(log10(n)) because we divide the input by 10 in each step.
     * The space complexity is O(1).
     *
     * @param x The integer to check.
     * @return true if the integer is a palindrome, false otherwise.
     */
    bool isPalindrome(int x) {
        // As per the problem description, negative numbers are not palindromes.
        // Also, if a number ends with 0 and is not 0 itself, it cannot be a palindrome.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            // Check for overflow before multiplication - though with problem constraints on x, this isn't strictly necessary.
            if (revertedNumber > std::numeric_limits<int>::max() / 10) {
                return false; // Should not happen with given constraints
            }
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber/10
        // For example, when the input is 12321, at the end of the while loop we get x = 12, revertedNumber = 123.
        // Since the middle digit doesn't matter for palindromicity, we can simply ignore it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
