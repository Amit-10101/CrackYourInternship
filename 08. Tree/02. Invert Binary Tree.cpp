class Solution {
public:
    void helper(TreeNode* root) {
        if (root == NULL) return;

        helper(root->left);
        helper(root->right);

        swap(root->left, root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};