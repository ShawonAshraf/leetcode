#include <iostream>
#include <vector>


/**
 * @class Solution
 * @brief Contains the logic for the "Remove Nth Node From End of List" problem.
 */
class Solution {
public:
    /**
     * @brief Removes the nth node from the end of a linked list in a single pass.
     *
     * This method uses a two-pointer approach to solve the problem in one pass.
     * 1. A dummy node is created and linked to the head of the list. This simplifies
     * edge cases, such as removing the head node itself.
     * 2. Two pointers, `slow` and `fast`, are initialized to the dummy node.
     * 3. The `fast` pointer is advanced `n + 1` steps ahead of the `slow` pointer.
     * 4. Then, both `slow` and `fast` pointers are moved forward one step at a time
     * until the `fast` pointer reaches the end of the list (nullptr).
     * 5. Because of the initial gap, when `fast` reaches the end, `slow` will be
     * positioned at the node just before the one that needs to be removed.
     * 6. The `slow` pointer's `next` reference is then updated to skip over the
     * target node, effectively removing it from the list.
     *
     * The time complexity is O(L) where L is the length of the list, as it's done in a single pass.
     * The space complexity is O(1).
     *
     * @param head The head of the linked list.
     * @param n The position from the end of the node to remove.
     * @return The head of the modified linked list.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 1. Create a dummy node to handle edge cases like removing the first node.
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // 3. Move the fast pointer n + 1 steps forward.
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        // 4. Move both pointers until the fast pointer reaches the end.
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // 5. & 6. The slow pointer is now at the node before the target node.
        // Remove the target node.
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory of the deleted node.

        ListNode* newHead = dummy->next;
        delete dummy; // Free the memory of the dummy node.
        
        return newHead;
    }
};
