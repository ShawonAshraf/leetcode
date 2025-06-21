#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @class Solution
 * @brief Contains the logic for the Container With Most Water problem.
 */
class Solution {
public:
    /**
     * @brief Finds the two lines that form a container with the most water.
     *
     * This method uses an efficient two-pointer approach. One pointer starts
     * from the beginning (left) and the other from the end (right) of the height array.
     * The area is calculated based on the shorter of the two lines and the distance
     * between them.
     *
     * In each step, we calculate the area and then move the pointer corresponding
     * to the shorter line inward. This is because moving the taller line's pointer
     * would only decrease the width, and the height would be limited by the same
     * shorter line, resulting in a smaller or equal area. By moving the shorter
     * line's pointer, we have a chance of finding a taller line that could
     * potentially create a larger area, despite the reduced width.
     *
     * The time complexity is O(n) because each pointer traverses the array once.
     * The space complexity is O(1).
     *
     * @param height A vector of integers representing the heights of the lines.
     * @return The maximum amount of water that can be stored.
     */
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate the width of the container
            int width = right - left;
            // The height of the container is limited by the shorter of the two lines
            int h = std::min(height[left], height[right]);
            
            // Calculate the current area
            int current_area = width * h;
            
            // Update the maximum area found so far
            max_area = std::max(max_area, current_area);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
