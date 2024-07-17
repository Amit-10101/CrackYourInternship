class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (um.find(diff) == um.end()) {
                um[nums[i]] = i;
            } else {
                ans.push_back(um[diff]);
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};