class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int i = 0;
        while (i < n) {
            int correct = nums[i] - 1;
            if (correct != i && nums[correct] != nums[i]) {
                swap(nums[correct], nums[i]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            int correct = nums[i] - 1;
            if (i != correct) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};