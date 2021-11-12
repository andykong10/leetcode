// ***
//
// Given a linked list, swap every two adjacent nodes and return its head.
//
// Example:
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Note:
// - Your algorithm should use only constant extra space.
// - You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// ***
//
// Recursive. Draw a picture and you should understand.
ListNode* swapPairs(ListNode* head) {
    if (!head or !head->next) {
        return head;
    }

    // head -> second -> head2 -> second ...
    // second -> head -> swapParis(head->next->next) ...

    ListNode* second = head->next;
    head->next = swapPairs(head->next->next);
    second->next = head;

    return second;
}
