class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* lca(Node* root, int a, int b) {
        if (root == NULL || root->data == a || root->data == b) {
            return root;
        }
        
        Node* left = lca(root->left, a, b);
        Node* right = lca(root->right, a, b);
        
        if (left == NULL && right == NULL) {
            return NULL;
        } else if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
    }
    
    int dist(Node* root, int target, int level) {
        if (root == NULL) return -1;
        
        if (root->data == target) return level;
        
        int left = dist(root->left, target, level+1);
        if (left != -1) {
            return left;
        }
        
        return dist(root->right, target, level+1);
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node* temp = lca(root, a, b);
        
        return dist(temp, a, 0) + dist(temp, b, 0);
    }
};