class Solution {
public:
    int find(string& s, int& i) {
        int n = s.size();
        int num = 0;
        while (i < n && (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            num = 10*num + (s[i++] - '0');
        }
        return num;
    }
    
    int calculate(string s) {
        int ans = 0;
        int n = s.size();
        vector<int> temp;
        
        int i = 0;
        temp.emplace_back(find(s, i));
        for (i = i; i < n; i++) {
            if (s[i] == ' ') continue;

            if (s[i] == '/') {
                i++;
                int num1 = temp.back();
                int num2 = find(s, i);
                i--;
                temp.pop_back();
                temp.emplace_back(int(num1 / num2));
            } else if (s[i] == '*') {
                i++;
                int num1 = temp.back();
                int num2 = find(s, i);
                i--;
                temp.pop_back();
                temp.emplace_back(int(num1 * num2));
            } else if (s[i] == '+' || s[i] == '-') {
                int sign = (s[i] == '-' ? -1 : 1);
                i++;
                int num = find(s, i);
                i--;
                temp.emplace_back(sign * num);
            }
        }

        while (!temp.empty()) {
            ans += temp.back();
            temp.pop_back();
        }

        return ans;
    }
};