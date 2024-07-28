class Solution {
public:
    int len(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = len(headA);
        int n2 = len(headB);
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (n1 != n2) {
            if (n1 > n2) {
                tempA = tempA->next;
                n1--;
            } else {
                tempB = tempB->next;
                n2--;
            }
        }

        while (tempA != NULL && tempB != NULL) {
            if (tempA == tempB) return tempA;

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return NULL;
    }
};