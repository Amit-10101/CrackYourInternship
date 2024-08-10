class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (i == n-1 && front) {
                    ans.push_back(front->val);
                }

                if (front && front->left) {
                    q.push(front->left);
                }
                if (front && front->right) {
                    q.push(front->right);
                }
            }
        }

        return ans;
    }
};