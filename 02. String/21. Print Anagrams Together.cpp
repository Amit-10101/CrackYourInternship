class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> um;

        for (string& s : string_list) {
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