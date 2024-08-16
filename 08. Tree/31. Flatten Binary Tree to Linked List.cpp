class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* temp = root;
        
        while (temp) {
            TreeNode* next = NULL;
            if (temp->left) {
                next = temp->left;
                while (next->right) {
                    next = next->right;
                }
                next->right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
            }
            temp = temp->right;
        }
    }
};