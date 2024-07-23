class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;

        for (string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            um[temp].push_back(s);
        }

        for (auto& p : um) {
            ans.push_back(p.second);
        }

        return ans;
    }
};