#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for finding all k-distant indices in an array.
 */
class Solution {
public:
    /**
     * @brief Finds all k-distant indices in an array.
     * A k-distant index `i` is one for which there exists at least one index `j`
     * such that |i - j| <= k and nums[j] == key.
     *
     * This method works in two main stages:
     * 1. It first iterates through the `nums` array to find all indices where the
     * value equals the `key`. These are stored in a `key_indices` vector.
     * 2. It then iterates through the `key_indices`. For each `key_index`, it
     * generates all indices `i` that are within `k` distance of it
     * (i.e., from `key_index - k` to `key_index + k`, within array bounds).
     * 3. A `std::set` is used to store these resulting indices. The set
     * automatically handles duplicates and keeps the indices sorted.
     * 4. Finally, the contents of the set are copied to a vector to be returned.
     *
     * The time complexity is O(N*K) in the worst case, but closer to O(N) if K is small
     * and the number of keys is distributed. Space complexity is O(M) where M is the
     * number of k-distant indices.
     *
     * @param nums The input vector of integers.
     * @param key The key value to search for.
     * @param k The maximum allowed distance.
     * @return A sorted list of all k-distant indices.
     */
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> key_indices;
        int n = nums.size();

        // 1. Find all indices where nums[j] == key
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                key_indices.push_back(j);
            }
        }

        std::set<int> result_set;
        // 2. For each key_index, find all indices within k distance
        for (int j : key_indices) {
            int start_i = std::max(0, j - k);
            int end_i = std::min(n - 1, j + k);
            for (int i = start_i; i <= end_i; ++i) {
                result_set.insert(i);
            }
        }

        // 4. Convert the set to a vector
        std::vector<int> result(result_set.begin(), result_set.end());
        return result;
    }
};
