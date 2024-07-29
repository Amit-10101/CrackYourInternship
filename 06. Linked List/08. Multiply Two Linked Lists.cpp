class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        Node* temp1 = first;
        Node* temp2 = second;
        long long n1 = 0, n2 = 0;
        long long mod = 1e9+7;
        
        while (temp1 != NULL) {
            n1 = (n1*10 + temp1->data) % mod;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            n2 = (n2*10 + temp2->data) % mod;
            temp2 = temp2->next;
        }
        
        return ((n1 * n2) % mod);
    }
};