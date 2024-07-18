class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int change = 1;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i-1] != nums[i]) {
                nums[change++] = nums[i];
            }
        }

        return change;
    }
};