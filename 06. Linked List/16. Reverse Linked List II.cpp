class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* back = NULL;
        ListNode* forw = NULL;
        for (int i = right; i >= left; i--) {
            forw = curr->next;
            curr->next = back;
            back = curr;
            curr = forw;
        }
        if (prev->next) prev->next->next = forw;
        prev->next = back;

        return dummy->next;
    }
};