class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }

            st.push(word);
            count++;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            count--;
            if (count != 0) ans += ' ';
        }

        return ans;
    }
};