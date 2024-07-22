class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool exp = false;
        bool dot = false;
        bool sign = false;
        bool digit = false;
        
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') return false;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!digit || exp) return false;
                exp = true;
                digit = false;
            } else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } else {
                return false;
            }
        }

        return digit;
    }
};