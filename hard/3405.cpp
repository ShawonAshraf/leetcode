#include <iostream>
#include <vector>
#include <string>

/**
 * @class Solution
 * @brief Contains the logic for the Number of Good Arrays problem.
 */
class Solution {
private:
    long long MOD = 1e9 + 7;

    /**
     * @brief Calculates (base^exp) % MOD using binary exponentiation.
     * This is efficient for large exponents.
     */
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    /**
     * @brief Calculates the modular multiplicative inverse of n modulo MOD.
     * Uses Fermat's Little Theorem: n^(MOD-2) % MOD.
     */
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

    /**
     * @brief Calculates combinations C(n, k) modulo MOD.
     * Uses precomputed factorials and their modular inverses for efficiency.
     */
    long long combinations(int n, int k, const std::vector<long long>& fact, const std::vector<long long>& invFact) {
        if (k < 0 || k > n) {
            return 0;
        }
        return (((fact[n] * invFact[k]) % MOD) * invFact[n - k]) % MOD;
    }

public:
    /**
     * @brief Calculates the number of "good arrays" of size n.
     * A good array has elements in [1, m] and exactly k adjacent equal pairs.
     *
     * The logic is combinatorial:
     * 1. Choose k positions for the equal adjacent pairs from n-1 possible positions: C(n-1, k).
     * 2. Choose the first element: m ways.
     * 3. For the k equal pairs, there's only 1 choice (must be same as previous).
     * 4. For the remaining (n-1-k) pairs, there are (m-1) choices (must be different).
     *
     * Total = C(n-1, k) * m * (m-1)^(n-1-k)
     * All calculations are done modulo 10^9 + 7.
     *
     * @param n The size of the array.
     * @param m The upper bound for element values.
     * @param k The required number of adjacent equal elements.
     * @return The number of good arrays modulo 10^9 + 7.
     */
    int countGoodArrays(int n, int m, int k) {
        if (k >= n) {
            return 0;
        }

        // Precompute factorials and their modular inverses up to n.
        std::vector<long long> fact(n);
        std::vector<long long> invFact(n);
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
            invFact[i] = modInverse(fact[i]);
        }
        
        // 1. Calculate C(n-1, k)
        long long ways_to_choose_k_positions = combinations(n - 1, k, fact, invFact);
        
        // 2. Calculate m
        long long ways_for_first_element = m;
        
        // 3. Calculate (m-1)^(n-1-k)
        long long ways_for_different_pairs = power(m - 1, n - 1 - k);
        
        // Combine the results
        long long result = (ways_to_choose_k_positions * ways_for_first_element) % MOD;
        result = (result * ways_for_different_pairs) % MOD;
        
        return (int)result;
    }
};