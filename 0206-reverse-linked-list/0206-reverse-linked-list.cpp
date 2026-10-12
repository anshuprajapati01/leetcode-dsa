class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move prev forward
            curr = next;                 // Move curr forward
        }

        return prev;
    }
};