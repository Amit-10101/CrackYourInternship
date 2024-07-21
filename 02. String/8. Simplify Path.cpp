class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (path[i] == '/') continue;

            string curr = "";
            while (i < n && path[i] != '/') {
                curr += path[i++];
            }
            
            if (curr == ".") {
                continue;
            } else if (curr == "..") {
                if (!st.empty()) st.pop();
            } else {
                st.push(curr);
            }
        }

        while (!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }

        return ans == "" ? "/" : ans;
    }
};