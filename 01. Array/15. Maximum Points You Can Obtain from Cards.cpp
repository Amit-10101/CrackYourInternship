class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans = 0;

        int left = 0;
        int right = 0;
        for (int i = 0; i < k; i++) {
            left += cardPoints[i];
        }

        ans = left;
        int end = n-1;
        for (int i = k-1; i >= 0; i--) {
            left -= cardPoints[i];
            right += cardPoints[end];
            ans = max(ans, left + right);
            end--;
        }

        return ans;
    }
};