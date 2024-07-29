class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = head;

        while (curr != NULL) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = reverse(l1);
        ListNode* temp2 = reverse(l2);
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        int carry = 0;

        while (temp1 || temp2) {
            int curr = (carry ? carry : 0);
            if (temp1) curr += temp1->val;
            if (temp2) curr += temp2->val;

            if (curr >= 10) {
                carry = curr/10;
                curr = curr - 10;
            } else {
                carry = 0;
            }
            dummy->next = new ListNode(curr);
            dummy = dummy->next;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        if (carry) dummy->next = new ListNode(carry);

        return reverse(ans->next);
    }
};