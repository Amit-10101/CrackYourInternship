class Solution
{
    public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* forw = head;

        while (curr != NULL) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        Node* temp = head;
        temp = reverse(temp);
        Node* dummy = new Node(0);
        Node* store = dummy;
        int currMax = temp->data;
        
        while (temp != NULL) {
            if (temp->data >= currMax) {
                currMax = temp->data;
                dummy->next = temp;
                dummy = dummy->next;
            }
            temp = temp->next;
        }
        dummy->next = NULL;
        
        store = reverse(store->next);
        return store;
    }  
};