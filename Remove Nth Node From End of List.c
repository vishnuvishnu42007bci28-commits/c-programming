/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to seamlessly handle head deletion
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // Move fast pointer so that there is a gap of n+1 nodes from slow
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow->next is the node to be deleted
    slow->next = slow->next->next;
    
    return dummy.next;
}
