class Solution {
public:
    void helper(TreeNode* root, int k, int& curr, int& ans) {
        if (root == NULL) return;

        helper(root->left, k, curr, ans);
        curr++;
        if (k == curr) {
            ans = root->val;
            return;
        } else if (k < curr) {
            return;
        }
        helper(root->right, k, curr, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int curr = 0;
        helper(root, k, curr, ans);

        return ans;
    }
};