class Solution {
public:
    int i = 0, j = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (i >= preorder.size()) return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        if (root->val != postorder[j]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if (root->val != postorder[j]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        j++;

        return root;
    }
};