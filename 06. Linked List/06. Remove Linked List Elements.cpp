class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        dummy->next = head;

        while (dummy != NULL && dummy->next != NULL) {
            while (dummy->next && dummy->next->val == val) {
                dummy->next = dummy->next->next;
            }
            dummy = dummy->next;
        }

        return temp->next;
    }
};