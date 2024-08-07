class Solution {
public:
    void helper(TreeNode* root, TreeNode*& prev, int& ans) {
        if (root == NULL) return;

        helper(root->left, prev, ans);

        if (prev != NULL) {
            ans = min(ans, abs(root->val - prev->val));
        }
        prev = root;

        helper(root->right, prev, ans);
    }

    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode* prev = NULL;
        helper(root, prev, ans);
        
        return ans;
    }
};