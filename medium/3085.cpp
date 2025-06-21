#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

/**
 * @class Solution
 * @brief Solves the problem of finding the minimum deletions to make a string k-special.
 *
 * A string is k-special if the absolute difference between the frequencies of any
 * two characters is no more than k. This solution calculates the minimum number
 * of character deletions required to meet this condition.
 */
class Solution {
public:
    /**
     * @brief Calculates the minimum number of characters to delete to make a word k-special.
     * @param word The input string, consisting of lowercase English letters.
     * @param k The maximum allowed difference between character frequencies.
     * @return The minimum number of deletions required.
     */
    int minimumDeletions(std::string word, int k) {
        // Step 1: Calculate the frequency of each character.
        // We use a vector of size 26 for direct mapping of 'a' through 'z'.
        std::vector<int> freq_map(26, 0);
        for (char c : word) {
            freq_map[c - 'a']++;
        }

        // Step 2: Collect all non-zero frequencies into a vector.
        // We only care about characters that actually appear in the string.
        std::vector<int> freqs;
        for (int freq : freq_map) {
            if (freq > 0) {
                freqs.push_back(freq);
            }
        }

        // If there are 0 or 1 distinct characters, the string is already k-special by definition.
        if (freqs.size() <= 1) {
            return 0;
        }

        // Step 3: Iterate through all possible target minimum frequencies (`min_val`)
        // and calculate the cost (deletions) for each.
        // The optimal `min_val` must be one of the existing frequencies, so we only
        // need to test those values as potential floor frequencies for our target range.
        int min_deletions = word.length(); // Initialize with the max possible deletions.

        // Sort frequencies to iterate through them as potential minimums.
        std::sort(freqs.begin(), freqs.end());
        
        // We create a set of unique frequencies to use as candidates for the minimum
        // frequency in the final k-special string.
        std::set<int> unique_freqs(freqs.begin(), freqs.end());
        unique_freqs.insert(0); // Also consider the case where we delete some characters entirely.

        for (int min_val : unique_freqs) {
            int current_deletions = 0;
            // The target frequency range for the final string will be [min_val, min_val + k].
            int max_val = min_val + k;

            // Calculate the cost for this target range [min_val, max_val].
            for (int f : freqs) {
                if (f < min_val) {
                    // If a character's frequency is below the floor of our range,
                    // we must delete all of its occurrences.
                    current_deletions += f;
                } else if (f > max_val) {
                    // If a character's frequency is above the ceiling of our range,
                    // we must delete just enough to bring it down to the ceiling.
                    current_deletions += f - max_val;
                }
                // If a character's frequency 'f' is already within the range
                // [min_val, max_val], no deletions are needed for that character.
            }
            // Update the overall minimum deletions found so far.
            min_deletions = std::min(min_deletions, current_deletions);
        }

        return min_deletions;
    }
};

