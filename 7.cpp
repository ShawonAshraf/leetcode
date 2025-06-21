#include <iostream>
#include <limits> // Required for std::numeric_limits

/**
 * @class Solution
 * @brief Contains the logic for the Reverse Integer problem.
 */
class Solution {
public:
    /**
     * @brief Reverses the digits of a 32-bit signed integer.
     *
     * This method reverses an integer by repeatedly taking the last digit
     * and appending it to a new 'reversed' number.
     *
     * Crucially, it checks for potential overflow before performing the
     * operation `reversed = reversed * 10 + pop`. It does this by comparing
     * the current `reversed` value against `INT_MAX / 10` and `INT_MIN / 10`.
     * This prevents the intermediate calculation from exceeding the 32-bit
     * integer limits, adhering to the problem constraints.
     *
     * If an overflow would occur, the function returns 0.
     *
     * @param x The 32-bit signed integer to reverse.
     * @return The reversed integer, or 0 if the reversal causes an overflow.
     */
    int reverse(int x) {
        int reversed = 0;
        const int INT_MAX_DIV_10 = std::numeric_limits<int>::max() / 10;
        const int INT_MIN_DIV_10 = std::numeric_limits<int>::min() / 10;

        while (x != 0) {
            // Get the last digit of x
            int pop = x % 10;
            x /= 10;

            // Check for positive overflow before multiplication
            // If reversed > INT_MAX / 10, then reversed * 10 will surely overflow.
            // If reversed == INT_MAX / 10, it overflows if pop > 7 (since INT_MAX ends in 7).
            if (reversed > INT_MAX_DIV_10 || (reversed == INT_MAX_DIV_10 && pop > 7)) {
                return 0;
            }

            // Check for negative overflow before multiplication
            // If reversed < INT_MIN / 10, then reversed * 10 will surely underflow.
            // If reversed == INT_MIN / 10, it underflows if pop < -8 (since INT_MIN ends in -8).
            if (reversed < INT_MIN_DIV_10 || (reversed == INT_MIN_DIV_10 && pop < -8)) {
                return 0;
            }

            // Append the popped digit to the reversed number
            reversed = reversed * 10 + pop;
        }
        return reversed;
    }
};
