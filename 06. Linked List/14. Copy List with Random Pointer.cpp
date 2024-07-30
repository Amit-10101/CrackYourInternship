class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* ans = dummy;
        Node* temp = head;
        unordered_map<Node*, Node*> um;

        while (temp != NULL) {
            dummy->next = new Node(temp->val);
            dummy = dummy->next;
            um[temp] = dummy;
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL) {
            um[temp]->random = um[temp->random];
            temp = temp->next;
        }

        return ans->next;
    }
};