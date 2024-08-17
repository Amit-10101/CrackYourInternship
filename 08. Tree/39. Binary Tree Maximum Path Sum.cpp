class Solution {
public:
    int helper(TreeNode* root, int& sum) {
        if (root == NULL) return 0;

        int left = max(0, helper(root->left, sum));
        int right = max(0, helper(root->right, sum));
        sum = max(sum, root->val + left + right);

        return root->val + max(left, right);
    }
	
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        
        int sum = INT_MIN;
        helper(root, sum);

        return sum;
    }
};