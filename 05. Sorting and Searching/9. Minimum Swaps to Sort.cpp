class Solution {
public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
	    // Code here
	    int n = nums.size();
        vector<pair<int, int>> temp;
        
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        
        sort(temp.begin(), temp.end());
        
	    int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != temp[i].second) {
                swap(temp[i], temp[temp[i].second]);
                i--;
                ans++;
            }
        }
	    
        return ans;
	}
};