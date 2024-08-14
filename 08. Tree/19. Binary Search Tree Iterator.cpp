class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            this->st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* root = this->st.top();
        int val = root->val;
        this->st.pop();
        
        if (root->right) {
            root = root->right;
            while (root) {
                this->st.push(root);
                root = root->left;
            }
        }

        return val;
    }
    
    bool hasNext() {
        return !this->st.empty();
    }
};