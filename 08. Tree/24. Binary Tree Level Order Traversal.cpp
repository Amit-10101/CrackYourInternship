class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front) {
                    temp.push_back(front->val);
                }
                if (front && front->left) {
                    q.push(front->left);
                }
                if (front && front->right) {
                    q.push(front->right);
                }
            }
            ans.push_back(temp);
        }    

        return ans;
    }
};