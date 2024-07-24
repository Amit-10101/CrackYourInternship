class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans(n);
        long long int prod = 1;
        
        int zero = 0;
        for (int num : nums) {
            if (num == 0)  {
                zero++;
                continue;
            }
            prod *= num;
        }
        
        for (int i = 0; i < n; i++) {
            if (zero > 1) {
                ans[i] = 0;
            } else if (zero == 1) {
                ans[i] = (nums[i] == 0 ? prod : 0);
            } else {
                ans[i] = prod / nums[i];
            }
        }
        
        return ans;
    }
};