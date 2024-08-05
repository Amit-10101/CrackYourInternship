class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) return true;
        if (root == nullptr || subRoot == nullptr) return false;

        bool ans = root->val == subRoot->val;
        ans = ans && check(root->left, subRoot->left);
        ans = ans && check(root->right, subRoot->right);

        return ans;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        if (root->val == subRoot->val && check(root, subRoot)) return true;

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);

        return left || right;
    }
};