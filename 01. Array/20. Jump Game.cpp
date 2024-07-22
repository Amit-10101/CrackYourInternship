class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;

        for (int i = 0; i < n; i++) {
            if (i > temp) {
                return false;
            }

            temp = max(temp, i + nums[i]);
            if (temp >= n - 1) {
                return true;
            }
        }

        return true;
    }
};