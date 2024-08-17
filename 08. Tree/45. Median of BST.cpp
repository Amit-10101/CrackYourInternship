int count(Node* root) {
    if (root == NULL) return 0;
    
    return 1 + count(root->left) + count(root->right);
}

void helper(Node* root, int& count, int n, int& curr, float& median) {
    if (root == NULL) return;

    helper(root->left, count, n, curr, median);

    curr++;
    if (n % 2 != 0 && curr == (n + 1) / 2) {
        median = root->data;
        return;
    } else if (n % 2 == 0 && curr == n / 2) {
        median = root->data;
    } else if (n % 2 == 0 && curr == n / 2 + 1) {
        median = (median + root->data) / 2.0;
        return;
    }

    helper(root->right, count, n, curr, median);
}

float findMedian(Node* root) {
    int n = count(root);
    int curr = 0;
    float median = 0;
    
    helper(root, n, n, curr, median);
    
    return median;
}