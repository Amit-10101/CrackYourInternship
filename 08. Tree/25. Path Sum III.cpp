class Solution {
public:
    unordered_map<long long int, int> um;
    void helper(TreeNode* root, long long int sum, int targetSum, int& ans) {
        if (root == NULL) return;

        sum += root->val;
        if (um.find(sum - targetSum) != um.end()) {
            ans += um[sum - targetSum];
        }
        um[sum]++;
        helper(root->left, sum, targetSum, ans);
        helper(root->right, sum, targetSum, ans);
        um[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;

        um[0] = 1;
        int ans = 0;
        helper(root, 0, targetSum, ans);

        return ans;
    }
};