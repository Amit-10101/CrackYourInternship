class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> rem(k, 0);
        int sum = 0;
        int ans = 0;

        rem[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];

            int currRem = sum % k;
            if (currRem < 0) currRem += k;
            ans += rem[currRem];
            rem[currRem]++;
        }

        return ans;
    }
};