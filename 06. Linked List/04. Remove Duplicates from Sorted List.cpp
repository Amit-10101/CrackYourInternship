class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = head;

        while (dummy != NULL) {
            int curr = dummy->val;
            ListNode* temp = dummy->next;

            while (temp != NULL && temp->val == curr) {
                temp = temp->next;
            }
            
            dummy->next = temp;
            dummy = dummy->next;
        }

        return head;
    }
};