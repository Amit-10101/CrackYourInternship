class Solution {
public:
    void helper(TreeNode* root, int low, int high, int& sum) {
        if (root == nullptr) return;

        if (low <= root->val && root->val <= high) {
            sum += root->val;
        }

        if (root->val >= low) {
            helper(root->left, low, high, sum);
        }

        if (root->val <= high) {
            helper(root->right, low, high, sum);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root, low, high, sum);
        
        return sum;
    }
};