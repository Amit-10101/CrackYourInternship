class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        bool order = true;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp(n, 0);

            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                int j = (order) ? i : n-i-1;
                temp[j] = front->val;

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
            order = !order;
        }

        return ans;
    }
};