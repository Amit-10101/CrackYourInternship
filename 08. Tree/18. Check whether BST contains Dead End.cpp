class Solution{
  public:
    bool helper(Node* root, int min, int max) {
        if (root == NULL) return false;
        
        int val = root->data;
        if (root->left == NULL && root->right == NULL) {
            if (val == min + 1 && val == max - 1) {
                return true;
            }
        }
        
        return helper(root->left, min, val) || helper(root->right, val, max);
    }
    
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return helper(root, 0, INT_MAX);
    }
};