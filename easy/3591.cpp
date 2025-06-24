#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

/**
 * @class Solution
 * @brief Contains the logic to check for prime frequencies of elements in an array.
 */
class Solution {
private:
    /**
     * @brief Checks if a given integer is a prime number.
     * A prime number is a natural number greater than 1 that has no positive
     * divisors other than 1 and itself.
     * @param n The number to check.
     * @return true if n is a prime number, false otherwise.
     */
    bool isPrime(int n) {
        // Prime numbers are natural numbers greater than 1.
        if (n <= 1) {
            return false;
        }
        // Check for divisibility from 2 up to the square root of n.
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false; // Found a divisor, so not prime.
            }
        }
        return true; // No divisors found, so it's a prime number.
    }

public:
    /**
     * @brief Determines if the frequency of any element in the array is a prime number.
     *
     * This method first calculates the frequency of each number in the input array
     * using a hash map. It then iterates through the frequencies. For each frequency,
     * it calls a helper function to check if that frequency is a prime number.
     * If any frequency is found to be prime, the function immediately returns true.
     * If the loop completes without finding any prime frequencies, it returns false.
     *
     * The time complexity is dominated by counting frequencies O(N) and then checking
     * each unique frequency for primality O(U * sqrt(F_max)), where N is the number of
     * elements, U is the number of unique elements, and F_max is the maximum frequency.
     * The space complexity is O(U) for the frequency map.
     *
     * @param nums The input vector of integers.
     * @return true if any element has a prime frequency, false otherwise.
     */
    bool checkPrimeFrequency(std::vector<int>& nums) {
        // Use a hash map to store the frequency of each number.
        std::unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Iterate through the frequency map.
        for (auto const& [num, freq] : freqMap) {
            // Check if the frequency is a prime number.
            if (isPrime(freq)) {
                return true; // Found a prime frequency, return true immediately.
            }
        }

        // No prime frequencies were found.
        return false;
    }
};