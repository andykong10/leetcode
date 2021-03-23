// ***
//
// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
// Note: Given n will always be valid.
//
// ***

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head->next) {
        return nullptr;
    }

    // slow->next is the node we would like to remove.
    ListNode *slow = head, *fast = head;

    for (int i = 0; i < n; ++i) {
        fast = fast->next;
    }

    // fast has reached one past the last element (the nullptr)
    // In this case number n given is the same as number of nodes in the linked list.
    // which means we need to remove the first element in the LinkedList, so simply return the second element as the new
    // head.
    if (!fast) {
        ListNode* toReturn = head->next;
        delete head;
        return toReturn;
    }

    // Otherwise, increment slow and fast together to the right,
    // until fast->next == nullptr, at this point slow->next reached the element which we want to remove.
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* toBeDeleted = slow->next;
    slow->next = slow->next->next;
    delete toBeDeleted;

    return head;
}
