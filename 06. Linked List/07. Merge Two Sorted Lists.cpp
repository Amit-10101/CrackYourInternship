class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                dummy->next = list1;
                list1 = list1->next;
            } else {
                dummy->next = list2;
                list2 = list2->next;
            }
            dummy = dummy->next;
        }

        while (list1 != NULL) {
            dummy->next = list1;
            list1 = list1->next;
            dummy = dummy->next;
        }
        while (list2 != NULL) {
            dummy->next = list2;
            list2 = list2->next;
            dummy = dummy->next;
        }

        return temp->next;
    }
};