class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        int minSize = INT_MAX;
        int ind = 0;
        for (int i = 0; i < n; i++) {
            int sz = strs[i].size();
            if (sz < minSize) {
                minSize = sz;
                ind = i;
            }
        }
        int ans = -1;
        for (int i = 0; i < minSize; i++) {
            char temp = strs[0][i];
            for (int j = 0; j < n; j++) {
                if (temp != strs[j][i]) {
                    ans = i;
                    return ans == -1 ? "" : strs[0].substr(0, ans);
                }
            }
        }

        return strs[ind];
    }
};