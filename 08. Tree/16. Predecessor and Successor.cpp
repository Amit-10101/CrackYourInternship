class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        if (root == NULL) return;
        
        if (root->key < key) {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        } else if (root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            findPreSuc(root->left, pre, suc, key);
            findPreSuc(root->right, pre, suc, key);
        }
    }
};