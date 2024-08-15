class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            Node* prev = NULL;
            int n = q.size();

            for (int i = 0; i < n; i++) {
                Node* front = q.front();
                q.pop();

                if (front && prev) {
                    prev->next = front;
                }
                prev = front;

                if (front && front->left) {
                    q.push(front->left);
                }
                if (front && front->right) {
                    q.push(front->right);
                }
            }
        }

        return root;
    }
};