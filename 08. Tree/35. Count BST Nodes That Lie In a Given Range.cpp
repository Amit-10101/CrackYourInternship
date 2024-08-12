class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if (root == NULL) return 0;
      
      int ans = 0;
      if (l <= root->data && root->data <= h) {
          ans++;
      }
      
      ans += getCount(root->left, l, h);
      ans += getCount(root->right, l, h);
      
      return ans;
    }
};