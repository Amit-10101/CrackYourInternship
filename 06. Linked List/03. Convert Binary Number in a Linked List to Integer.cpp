class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* dummy = head;

        int ans = dummy->val;
        dummy = dummy->next;
        
        while (dummy != NULL) {
            ans <<= 1;
            ans ^= dummy->val;
            dummy = dummy->next;
        }

        return ans;
    }
};