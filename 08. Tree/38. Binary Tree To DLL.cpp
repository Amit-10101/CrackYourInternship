class Solution {
  public:
    void helper(Node* root, Node*& prev, Node*& head) {
        if (root == NULL) return;
        
        helper(root->left, prev, head);
        if (prev) {
            prev->right = root;
            root->left = prev;
        } else {
            head = root;
        }
        
        prev = root;
        helper(root->right, prev, head);
    }
    
    Node* bToDLL(Node* root) {
        // code here
        Node* head = NULL;
        Node* prev = NULL;
        
        helper(root, prev, head);
        
        return head;
    }
};