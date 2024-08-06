class Solution {
public:
    void helper(TreeNode* root, string temp, vector<string>& ans) {
        if (root == NULL) {
            return;
        }

        temp += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        temp += "->";
        helper(root->left, temp, ans);
        helper(root->right, temp, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        helper(root, temp, ans);

        return ans;
    }
};