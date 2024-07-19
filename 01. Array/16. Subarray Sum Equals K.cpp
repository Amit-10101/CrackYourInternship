class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int n = nums.size();
        int sum = 0;
        int ans = 0;

        um[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int prev = sum - k;

            if (um.count(prev)) {
                ans += um[prev];
            }
            um[sum]++;
        }

        return ans;
    }
};