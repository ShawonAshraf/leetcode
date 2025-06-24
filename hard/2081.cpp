#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

/**
 * @class Solution
 * @brief Contains the logic for the Sum of k-Mirror Numbers problem.
 */
class Solution {
private:
    /**
     * @brief Converts a number to its base-k string representation and checks if it's a palindrome.
     * @param n The number to check.
     * @param k The base to convert to.
     * @return true if the base-k representation is a palindrome, false otherwise.
     */
    bool isPalindromeInBaseK(long long n, int k) {
        std::string baseKStr;
        if (n == 0) {
            baseKStr = "0";
        }
        
        long long temp = n;
        while (temp > 0) {
            baseKStr += std::to_string(temp % k);
            temp /= k;
        }

        std::string reversedStr = baseKStr;
        std::reverse(reversedStr.begin(), reversedStr.end());
        
        return baseKStr == reversedStr;
    }

public:
    /**
     * @brief Calculates the sum of the n smallest k-mirror numbers.
     * A k-mirror number is a positive integer that is a palindrome in both base-10 and base-k.
     *
     * This method works by systematically generating base-10 palindromes of increasing length
     * and checking if they are also palindromes in base-k.
     *
     * 1. It generates base-10 palindromes by length (1, 2, 3, ...).
     * 2. For each length `len`, it determines the range for the first half of the number.
     * 3. It iterates through the numbers in this range, constructing a full palindrome
     * from each (e.g., from '12' it creates '121' for odd length and '1221' for even length).
     * 4. Each generated base-10 palindrome is then checked to see if its base-k
     * representation is also a palindrome.
     * 5. The first `n` numbers that satisfy this condition are summed up.
     *
     * @param k The base to check for palindromicity, in addition to base-10.
     * @param n The number of k-mirror numbers to find and sum.
     * @return The sum of the n smallest k-mirror numbers.
     */
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;

        for (int len = 1; ; ++len) { // Loop over the length of the base-10 palindrome
            long long start = pow(10, (len - 1) / 2);
            long long end = pow(10, (len + 1) / 2);

            for (long long i = start; i < end; ++i) {
                std::string first_half = std::to_string(i);
                std::string second_half = first_half;
                std::reverse(second_half.begin(), second_half.end());

                std::string palindrome_str;
                if (len % 2 == 1) { // Odd length
                    palindrome_str = first_half + second_half.substr(1);
                } else { // Even length
                    palindrome_str = first_half + second_half;
                }
                
                long long p_num = std::stoll(palindrome_str);

                if (isPalindromeInBaseK(p_num, k)) {
                    sum += p_num;
                    count++;
                    if (count == n) {
                        return sum;
                    }
                }
            }
        }
        return sum; // Should be unreachable given constraints
    }
};