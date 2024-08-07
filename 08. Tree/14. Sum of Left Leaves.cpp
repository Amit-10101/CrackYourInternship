class Solution {
public:
    void helper(TreeNode* root, bool left, int& sum) {
        if (root == NULL) return;

        if (left && root->left == NULL && root->right == NULL) sum += root->val;

        helper(root->left, true, sum);
        helper(root->right, false, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, false, sum);

        return sum;
    }
};