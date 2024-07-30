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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = reverse(slow);
        slow = head;
        while (fast->next != NULL) {
            ListNode* slow_next = slow->next;
            ListNode* fast_next = fast->next;
            slow->next = fast;
            fast->next = slow_next;
            slow = slow_next;
            fast = fast_next;
        } 
    }
};