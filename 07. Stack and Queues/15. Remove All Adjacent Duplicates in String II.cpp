class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            if (!st.empty() && s[st.top().first] == s[i]) {
                st.top().second++;
                if (st.top().second == k) st.pop();
            } else {
                st.push({i, 1});
            }
        }

        string ans = "";
        while (!st.empty()) {
            for (int i = 0; i < st.top().second; i++) {
                ans.push_back(s[st.top().first]);
            }
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};