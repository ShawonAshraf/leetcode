#include <iostream>
#include <vector>

/**
 * @class Solution
 * @brief Contains the logic to solve the Add Two Numbers problem.
 */
class Solution {
public:
    /**
     * @brief Adds two numbers represented by linked lists.
     * The digits are stored in reverse order. This function iterates through
     * both lists, simulating elementary school addition from right to left.
     * A 'carry' value is maintained and propagated to the next digit.
     * A new linked list is created to store the sum.
     *
     * @param l1 The head of the first linked list.
     * @param l2 The head of the second linked list.
     * @return The head of the resulting linked list representing the sum.
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head to simplify handling of the new list's beginning.
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Loop as long as there are digits in l1, l2, or there's a carry.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the value from the current node of l1, or 0 if l1 is exhausted.
            int val1 = (l1 != nullptr) ? l1->val : 0;
            // Get the value from the current node of l2, or 0 if l2 is exhausted.
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of the digits plus any carry from the previous position.
            int sum = val1 + val2 + carry;
            // The new digit is the sum modulo 10.
            int newDigit = sum % 10;
            // The new carry is the integer division of the sum by 10.
            carry = sum / 10;

            // Create a new node with the new digit and append it to the result list.
            current->next = new ListNode(newDigit);
            
            // Move all pointers forward.
            current = current->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // The list starts after the dummy head, so we return dummyHead->next.
        ListNode* resultHead = dummyHead->next;
        delete dummyHead; // Clean up the dummy head node.
        return resultHead;
    }
};

// Helper function to create a linked list from a vector of integers.
ListNode* createLinkedList(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list.
void printLinkedList(ListNode* head) {
    if (!head) {
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[";
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << ",";
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

// Helper function to delete a linked list and free memory.
void deleteLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}
