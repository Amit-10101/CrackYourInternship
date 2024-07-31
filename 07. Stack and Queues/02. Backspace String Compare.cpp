class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;
        stack<char> st2;
        for (char c : s) {
            if (c == '#') {
                if (!st.empty()) st.pop();
            } else {
                st.push(c);
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(c);
            }
        }

        while (!st.empty() && !st2.empty()) {
            if (st.top() != st2.top()) return false;
            st.pop();
            st2.pop();
        }

        return st.empty() && st2.empty();
    }
};