class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        st.push(n-1);
        for (int i = n-2; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    vector<int> prevSmallerOrEqualElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int ans = 0;
        long long int mod = 1e9 + 7;

        vector<int> prev = prevSmallerOrEqualElement(arr);
        vector<int> next = nextSmallerElement(arr);
        
        for (int i = 0; i < n; i++) {
            int back = (prev[i] == -1) ? i + 1 : i - prev[i];
            int forw = (next[i] == -1) ? n - i : next[i] - i;

            ans = (ans + (((arr[i] * back) % mod) * forw) % mod) % mod;
        }

        return ans;
    }
};