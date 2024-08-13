class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    int i = 0;
    Node* Bst(int pre[], int size, int min = INT_MIN, int max = INT_MAX) {
        if (i >= size || pre[i] < min || pre[i] > max) {
            return NULL;
        }
        // code here
        Node* root = newNode(pre[i++]);
        root->left = Bst(pre, size, min, root->data);
        root->right = Bst(pre, size, root->data, max);
        
        return root;
    }
};