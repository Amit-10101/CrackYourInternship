class Solution {
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size() - 1, false);
    }

private:
    bool helper(const string& s, int left, int right, bool skipped) {
        while (left < right) {
            if (s[left] != s[right]) {
                if (skipped) {
                    return false;
                } else {
                    return helper(s, left+1, right, true) || helper(s, left, right-1, true);
                }
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
};