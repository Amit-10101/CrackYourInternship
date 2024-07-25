class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        for (int i = 0; i < m; i++) {
            if (haystack[i] == needle[0]) {
                int temp = i;
                bool flag = true;
                for (int j = 0; j < n; j++) {
                    if (haystack[temp] != needle[j]) {
                        flag = false;
                        break;
                    }
                    temp++;
                }

                if (flag) return i;
            }
        }

        return -1;
    }
};
