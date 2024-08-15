class Solution {
public:
    void helper(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
        if (root == NULL) return;

        helper(root->left, prev, first, second);

        if (prev && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
                second = root;
            } else {
                second = root;
                return;
            }
        }
        prev = root;

        helper(root->right, prev, first, second);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;

        helper(root, prev, first, second);

        if (first && second) {
            swap(first->val, second->val);
        } else {
            swap(first->val, prev->val);
        }
    }
};