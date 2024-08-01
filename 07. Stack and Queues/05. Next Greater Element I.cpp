class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1, -1);
        unordered_map<int, int> um;

        for (int i = 0; i < n2; i++) {
            um[nums2[i]] = i;
        }
        
        for (int i = 0; i < n1; i++) {
            int curr = um[nums1[i]];
            for (int j = curr+1; j < n2; j++) {
                if (nums2[j] > nums1[i]) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};