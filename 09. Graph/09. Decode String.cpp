class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        string ans = "";

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c != ']') {
                st.push(c);
            } else {
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                string num_str = "";
                while (!st.empty() && isdigit(st.top())) {
                    num_str = st.top() + num_str;
                    st.pop();
                }
                int num = stoi(num_str);

                string temp2 = "";
                for (int j = 0; j < num; j++) {
                    temp2 += temp;
                }
                for (char t : temp2) {
                    st.push(t);
                }
            }
        }

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};