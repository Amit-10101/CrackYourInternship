class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

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

    bool isPalindrome(ListNode* head) {
        bool ans = true;
        if (head == NULL || head->next == NULL) return ans;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverse(slow);
        fast = head;
        ListNode* repair = slow;

        while (fast != NULL && slow != NULL) {
            if (fast->val != slow->val) {
                ans = false;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }

        prev->next = reverse(repair);

        return ans;
    }
};