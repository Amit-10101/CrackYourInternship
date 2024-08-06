class Solution {
public:
    bool helper(TreeNode* root, int temp, int target) {
        if (root == NULL) {
            return false;
        }

        temp += root->val;
        if (temp == target && root->left == NULL && root->right == NULL) {
            return true;
        }

        if (helper(root->left, temp, target) || helper(root->right, temp, target)) {
            return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int temp = 0;
        return helper(root, temp, targetSum);
    }
};