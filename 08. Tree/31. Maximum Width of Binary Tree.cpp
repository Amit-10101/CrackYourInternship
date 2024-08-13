class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 0});

        unsigned long long int ans = 0;
        int max_ind = 0;
        while (!q.empty()) {
            int sz = q.size();
            unsigned long long int first = 0, last = 0;
            unsigned long long int min_ind = q.front().second;
            for (int i = 0; i < sz; i++) {
                TreeNode* front = q.front().first;
                unsigned long long int ind = q.front().second - min_ind;
                q.pop();

                if (i == 0) first = ind;
                if (i == sz-1) last = ind;

                if (front && front->left) {
                    q.push({front->left, 2*ind});
                }
                if (front && front->right) {
                    q.push({front->right, 2*ind+1});
                }
            }

            ans = max(ans, last-first+1);
        }

        return ans;
    }
};