class Solution {
public:
    int helper(TreeNode* root, int& diameter) {
        if (root == NULL) {
            return 0;
        }

        int left = helper(root->left, diameter);
        int right = helper(root->right, diameter);
        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        helper(root, diameter);

        return diameter;
    }
};